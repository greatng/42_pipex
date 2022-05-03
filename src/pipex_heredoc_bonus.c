/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:12:24 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/16 01:58:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../gnl/get_next_line.h"

/*
static	void	ft_get(t_box box, int lim_len, char *buff)
{
	int		byteread;
	char	*input;
	char	*tmp;

	input = NULL;
	while (byteread)
	{
		byteread = read(STDIN_FILENO, &buff, lim_len);
		buff[byteread] = '\0';
		if (ft_strncmp(buff, box->limiter, lim_len))
		{
			tmp = ft_strjoin(input, buff);
			if (input)
				free(input);
			input = tmp;
		}
		else
			break;
	}
}
*/

void	ft_heredoc(t_box *box)
{
	char	*ret;
	char	*infile;

	box->start = 2;
	box->limiter = box->argv[2];
	pipe(box->pipefd);
	while (1)
	{
		ret = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(ret, box->limiter, ft_strlen(ret) - 1))
		{
			free(ret);
			break ;
		}
		write(box->pipefd[1], ret, ft_strlen(ret));
		free(ret);
	}
	box->fd[0] = box->pipefd[0];
	close(box->pipefd[1]);
	infile = box->argv[box->argc - 1];
	box->fd[1] = open(infile, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (box->fd[1] == -1)
		ft_error(infile, *box);
}
