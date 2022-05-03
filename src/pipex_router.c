/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_router.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:06:00 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/31 11:46:06 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_cmdcheck(t_box *box, char *str)
{
	int		i;
	char	**cmd_split;
	char	*cmd;

	box->error = 0;
	cmd_split = ft_split(str, ' ');
	i = 0;
	while (box->envp[i])
	{
		cmd = ft_strjoin(box->envp[i++], cmd_split[0]);
		if (!access(cmd, 0))
		{
			free(cmd);
			return (cmd_split);
		}
		free(cmd);
	}
	box->error = 127;
	return (cmd_split);
}

//all works except write file execute here by child process
static void	ft_child_mid(t_box *box, int *pipefd, char **cmd_arg, char **envp)
{
	int		i;
	char	*cmd;

	i = 0;
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Dup in child_mid error 1", *box);
	while (box->envp[i])
	{
		cmd = ft_strjoin(box->envp[i++], cmd_arg[0]);
		if (!access(cmd, 0))
			break ;
		free(cmd);
	}
	execve(cmd, cmd_arg, envp);
	ft_putstr_fd(cmd_arg[0], 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_error("", *box);
}

static void	ft_child_out(t_box *box, int *pipefd, char **envp)
{
	int		i;
	char	*cmd;

	if (dup2(box->fd[1], STDOUT_FILENO) == -1)
		ft_error("Dup in child_out error 1", *box);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Dup in child_out error 2", *box);
	i = 0;
	while (box->envp[i])
	{
		cmd = ft_strjoin(box->envp[i++], box->cmdout[0]);
		if (!access(cmd, 0))
			break ;
		free(cmd);
	}
	execve(cmd, box->cmdout, envp);
	box->error = 127;
	ft_putstr_fd(box->cmdout[0], 2);
	ft_putstr_fd(": command not found", 2);
	ft_error("", *box);
}

//fork new child process and execute cmd
//each read end(fd[0]) of pipe connect to new one by parent process
static void	ft_call_mid(t_box *box, char **envp)
{
	int			i;
	pid_t		id;
	char		**cmd_arg;

	i = box->start;
	while (++i < box->argc - 2)
	{	
		cmd_arg = ft_cmdcheck(box, box->argv[i]);
		if (i - 1 > box->start)
			close(box->pipefd[0]);
		pipe(box->pipefd);
		id = fork();
		if (id < 0)
			ft_error("error :", *box);
		if (!id)
			ft_child_mid(box, box->pipefd, cmd_arg, envp);
		close(box->pipefd[1]);
		ft_free(cmd_arg);
		if (dup2(box->pipefd[0], STDIN_FILENO) == -1)
			ft_error("error :", *box);
	}
}

//Duplicate opened file to STDIN first 
void	ft_pipex(t_box *box, char **envp)
{
	pid_t	id_child;
	char	**tmp;

	if (dup2(box->fd[0], STDIN_FILENO) == -1)
		ft_error("error :", *box);
	close(box->fd[0]);
	ft_call_mid(box, envp);
	tmp = ft_cmdcheck(box, box->cmdout[0]);
	ft_free(tmp);
	id_child = fork();
	if (id_child < 0)
		ft_error("error :", *box);
	if (id_child == 0)
		ft_child_out(box, box->pipefd, envp);
	waitpid(id_child, NULL, 0);
	close(box->pipefd[0]);
	close(0);
	ft_free(box->envp);
	ft_free(box->cmdout);
}
