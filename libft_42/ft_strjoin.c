/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:24:38 by ckunimur          #+#    #+#             */
/*   Updated: 2022/09/26 14:15:47 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	size_len;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size_len = ft_strlen((char *)s1) + ft_strlen ((char *)s2);
	p = ft_calloc(size_len + 1, (sizeof(char)));
	while (i < size_len)
	{
		if (i < ft_strlen((char *)s1))
		p[i] = s1[i];
		if (i >= ft_strlen((char *)s1))
		{
		p[i] = s2[j];
		j++;
		}
		i++;
	}
	p[i] = '\0';
	return (p);
}
