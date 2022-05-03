/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:17:14 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/20 01:53:24 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;

	if (!(lst && f && del))
		return (0);
	result = 0;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
