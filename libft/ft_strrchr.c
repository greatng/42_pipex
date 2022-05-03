/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:26:59 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/17 21:49:05 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	end;

	end = ft_strlen(s);
	s += end;
	while (end >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		end--;
	}
	return (0);
}
