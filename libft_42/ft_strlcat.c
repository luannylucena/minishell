/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:55:02 by ckunimur          #+#    #+#             */
/*   Updated: 2022/09/22 19:27:06 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	c = 0;
	k = i;
	if (size <= i)
	{
		return (j + size);
	}
	else
	{
		while (i < size - 1 && src[c] != '\0')
		{
			dst[i] = ((char *)src)[c];
			i++;
			c++;
		}
		dst[i] = '\0';
	}
	return (k + j);
}
