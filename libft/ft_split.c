/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:11:12 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/21 19:11:22 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_word(char const *s, char c, char **split, size_t i)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	split[i] = malloc(sizeof(char) * (pos + 1));
	if (!split[i])
		return ;
	pos = 0;
	while (s[pos] && s[pos] != c)
	{
		split[i][pos] = s[pos];
		pos++;
	}
	s += pos;
	split[i][pos] = '\0';
	return ;
}

static	char	*ft_wordstart(char const *s, char c, size_t ln)
{
	size_t	i;

	i = 0;
	while (s[i] == c && s[i + 1] == c)
		i++;
	while (s[i])
	{
		if (ln == 0 && s[i] != c && i == 0)
			return ((char *)&s[i]);
		if ((s[i] == c && s[i + 1] != c))
			return ((char *)&s[i + 1]);
		i++;
	}
	return ((char *)s);
}

static	size_t	ft_count(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*cur;
	size_t	n;
	size_t	i;

	if (!s)
		return (0);
	n = ft_count(s, c);
	split = malloc(sizeof(char *) * (n + 1));
	if (!split)
		return (0);
	split[n] = NULL;
	i = 0;
	cur = (char *)s;
	while (i < n)
	{
		cur = ft_wordstart(cur, c, i);
		ft_word(cur, c, split, i);
		if (!split[i])
			return (0);
		i++;
	}
	return (split);
}
