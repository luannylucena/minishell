/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:43:40 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/07 22:17:58 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	unsigned int	count;

	count = 1;
	if (s[0] == c || !*s)
		count = 0;
	while (*s)
	{
		if (*s == c && s[+1] != c && s[+1] != '\0')
			count++;
		s++;
	}
	return (count);
}

static int	ft_strsize(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	j;
	size_t	k;
	size_t	size;
	char	**p;

	j = 0;
	k = 0;
	size = 0;
	count = (ft_count_str(s, c));
	p = (char **)ft_calloc(count + 1, sizeof(char *));
	while (j < count)
	{
		while (*s == c)
			s++;
		size = ft_strsize(s, c);
		p[j] = (char *)ft_calloc(size + 1, sizeof(char));
		while (k < size)
			p[j][k++] = *s++;
		k = 0;
		s++;
		j++;
	}
	return (p);
}
