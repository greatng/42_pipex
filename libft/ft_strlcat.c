/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:13:58 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/17 15:02:13 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	needed;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	needed = dstlen + srclen;
	i = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (i < srclen && dstlen < dstsize - 1)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (needed);
}
