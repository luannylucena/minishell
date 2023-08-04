/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:26:24 by ckunimur          #+#    #+#             */
/*   Updated: 2022/09/24 00:31:01 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*p;

	s_len = ft_strlen(s);
	i = 0;
	if (len >= s_len)
		len = (s_len - start);
	if (start >= s_len)
	{
		return (ft_calloc(1, (sizeof(char))));
	}
	p = ft_calloc(len + 1, (sizeof(char)));
	if (s)
	{
		while (i < len && s[start + i] != '\0')
		{
			p[i] = s[start + i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
