/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:53:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/17 20:03:46 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (!needle[0])
	{
		return (str);
	}
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == needle[0])
		{
			while (str[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (!needle[j])
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
