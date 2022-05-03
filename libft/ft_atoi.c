/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:34:32 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/20 02:40:20 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_skipwhitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			return (i);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			neg;
	long int	result;

	i = ft_skipwhitespace(str);
	neg = 1;
	result = 0;
	if ((str[i] == '-' && ft_isdigit(str[i + 1])))
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * neg);
}
