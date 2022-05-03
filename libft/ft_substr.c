/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:59:08 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/18 00:41:42 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	size;

	n = start;
	size = len + 1;
	if (ft_strlen(s) < len)
		size = ft_strlen(s);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[n] && n < ft_strlen(s))
	{
		str[i] = s[n];
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
