/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:49:14 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/20 02:43:59 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_str;
	unsigned char	*dst_str;
	size_t			i;

	src_str = (unsigned char *)src;
	dst_str = (unsigned char *)dst;
	if (!src_str && !dst_str)
		return (0);
	i = 0;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst);
}
