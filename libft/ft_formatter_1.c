/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:59:26 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/24 17:56:54 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(t_print *tab)
{
	int	c;

	c = va_arg(tab->args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_s(t_print *tab)
{
	char	*s;

	s = va_arg(tab->args, char *);
	if (s)
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (0);
}

int	ft_print_nb(t_print *tab)
{
	int		nb;
	int		ret;
	int		plus;
	char	*s;

	plus = 0;
	nb = va_arg(tab->args, int);
	if (tab->plus && nb >= 0)
		plus = write(1, "+", 1);
	if (tab->space && nb >= 0)
		plus = write(1, " ", 1);
	tab->plus = 0;
	ft_putnbr_fd(nb, 1);
	s = ft_itoa(nb);
	ret = ft_strlen(s) + plus;
	free (s);
	return (ret);
}

int	ft_print_u(t_print *tab)
{
	unsigned int	u;
	char			*s;
	int				len;

	u = va_arg(tab->args, unsigned int);
	s = ft_utoa(u);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}
