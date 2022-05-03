/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:47:00 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/28 12:35:41 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

static size_t	ft_getlast(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (ft_checkset(s1[i], set))
		{
			if (i == 0)
				return (i);
			i--;
		}
		else
			return (i);
	}
	return (0);
}

static size_t	ft_getfirst(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_checkset(s1[i], set))
			i++;
		else
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	i = ft_getfirst(s1, set);
	j = ft_getlast(s1, set);
	if (j >= i)
		size = j - i + 1;
	else
		size = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		return (0);
	}
	j = 0;
	while (j < size)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
