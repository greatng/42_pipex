/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:49:13 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/12 20:44:56 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			c;
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		write(fd, "-", 1);
	}
	c = nbr % 10;
	nbr = nbr / 10;
	if (nbr)
		ft_putnbr_fd(nbr, fd);
	write(fd, &"0123456789"[c], 1);
}
