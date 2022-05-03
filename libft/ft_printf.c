/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:39:35 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/24 17:57:08 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_eval_format(t_print *tab, const char *format, int i);

static int	ft_flag(t_print *tab, const char *format, int i)
{
	int	j;

	j = i;
	if (format[i] == '#')
	{
		tab->sharp = 1;
		while (format[i] == '#' || format[i] == ' ')
			i++;
	}
	else if (format[i] == '+')
	{
		tab->plus = 1;
		while (format[i] == '+')
			i++;
	}
	else if (format[i] == ' ')
	{
		tab->space = ' ';
		while (format[i] == ' ')
			i++;
	}
	ft_eval_format(tab, format, i);
	return (i - j);
}

static int	ft_eval_format(t_print *tab, const char *format, int i)
{
	int	n;

	n = 1;
	if (format[i] == '%')
		tab->tl += (write(1, "%", 1));
	else if (format[i] == 'c')
		tab->tl += ft_print_c(tab);
	else if (format[i] == 's')
		tab->tl += ft_print_s(tab);
	else if (format[i] == 'p')
		tab->tl += ft_print_p(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		tab->tl += ft_print_nb(tab);
	else if (format[i] == 'u')
		tab->tl += ft_print_u(tab);
	else if (format[i] == 'x')
		tab->tl += ft_print_x(tab, 'x');
	else if (format[i] == 'X')
		tab->tl += ft_print_x(tab, 'X');
	else
		n += ft_flag(tab, format, i);
	return (n);
}

static int	ft_finalize(t_print *tab, int ret)
{
	int	tl;

	tl = tab->tl;
	free (tab);
	return (ret + tl);
}

static	t_print	*ft_initialise_tab(t_print *tab)
{
	tab->i = 0;
	tab->tl = 0;
	tab->sharp = 0;
	tab->plus = 0;
	tab->space = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	while (format[tab->i])
	{
		if (format[tab->i] == '%')
			tab->i += ft_eval_format(tab, format, tab->i + 1);
		else
			ret += write(1, &format[tab->i], 1);
		tab->i += 1;
	}
	va_end(tab->args);
	ret = ft_finalize(tab, ret);
	return (ret);
}
/*
int	main(void)
{
	ft_printf("%p", (void *)-1);
	ft_printf("\n");
	//printf("This %p is even stranger", (void *)-1);
}
*/
