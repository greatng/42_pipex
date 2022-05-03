/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:48:07 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/20 02:44:43 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_str;
	unsigned char	*dst_str;
	size_t			i;

	i = 0;
	src_str = (unsigned char *)src;
	dst_str = (unsigned char *)dst;
	if (!src_str && !dst_str)
		return (0);
	if (dst_str > src_str)
	{
		while (len-- > 0)
			dst_str[len] = src_str[len];
	}
	else
	{
		while (i < len)
		{
			dst_str[i] = src_str[i];
			i++;
		}
	}
	return (dst);
}
