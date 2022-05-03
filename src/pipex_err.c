/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:28:08 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/31 10:47:19 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str_err, t_box box)
{
	if (box.cmdout)
		ft_free(box.cmdout);
	if (box.envp)
		ft_free(box.envp);
	if (errno == 2 && box.error != 127)
	{
		perror(str_err);
		exit(1);
	}
	if (box.error == 0 || box.error == 1)
	{
		perror(str_err);
		exit(box.error);
	}
	else
	{
		ft_putstr_fd(str_err, 2);
		ft_putchar_fd('\n', 2);
		exit(box.error);
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	if (str != NULL)
		free(str);
}
