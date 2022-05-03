/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:38:22 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/24 17:57:36 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(t_print *tab)
{
	unsigned long	p;
	int				len;

	p = va_arg(tab->args, unsigned long);
	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_base_p(p, "0123456789abcdef", 16);
	return (len);
}

int	ft_print_x(t_print *tab, char u)
{
	unsigned int	x;
	int				len;

	x = va_arg(tab->args, unsigned int);
	len = 0;
	if (tab->sharp && x)
	{
		tab->sharp = 0;
		if (u == 'x')
			len += write(1, "0x", 2);
		else
			len += write(1, "0X", 2);
	}
	if (u == 'x')
		len += ft_print_base(x, "0123456789abcdef", 16);
	else
		len += ft_print_base(x, "0123456789ABCDEF", 16);
	return (len);
}
