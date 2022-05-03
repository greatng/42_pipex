/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:49:25 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/31 01:20:33 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
//# include "get_next_line.h"

//write pipefd[1] read pipefd[0]
typedef struct s_box
{
	int		fd[2];
	int		argc;
	int		pipefd[2];
	int		start;
	int		error;
	char	**argv;
	char	**envp;
	char	**cmdout;
	char	*limiter;
}	t_box;
//if start == 1 : normal operation
//if start == 2 : here_doc
void	ft_pipex(t_box *box, char **envp);
void	ft_error(char *err_str, t_box box);
void	ft_heredoc(t_box *box);
void	ft_free(char **str);
//void	ft_pipe_bonus(t_box box);

#endif