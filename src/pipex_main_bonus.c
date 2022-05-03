/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:13:00 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/09 02:13:03 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//parsing env variable
static void	ft_env(t_box *box)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (!ft_strnstr(box->envp[i], "PATH=", 5))
		i++;
	box->envp = ft_split(box->envp[i], ':');
	tmp = ft_strtrim(box->envp[0], "PATH=");
	free(box->envp[0]);
	box->envp[0] = tmp;
	j = 0;
	while (box->envp[j])
	{
		tmp = ft_strjoin(box->envp[j], "/");
		free(box->envp[j]);
		box->envp[j++] = tmp;
	}
}

static void	ft_boxinit(int argc, char **argv, char **envp, t_box *box)
{
	box->argc = argc;
	box->argv = argv;
	box->envp = envp;
	box->start = 1;
	ft_env(box);
	box->cmdout = ft_split(argv[argc - 2], ' ');
	box->fd[0] = 0;
	box->fd[1] = 0;
	box->error = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_box	box;

	if (argc < 5)
	{
		ft_printf("Invalid number of arguments.\n");
		exit(1);
	}
	ft_boxinit(argc, argv, envp, &box);
	if (!ft_strncmp(argv[1], "here_doc", 8) && argc == 6)
		ft_heredoc(&box);
	else
	{
		box.fd[0] = open(argv[1], O_RDONLY, 0644);
		box.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (box.fd[0] == -1)
		ft_error(argv[1], box);
	if (box.fd[1] == -1)
	{
		box.error = 1;
		ft_error(argv[argc - 1], box);
	}
	ft_pipex(&box, envp);
	return (box.error);
}
