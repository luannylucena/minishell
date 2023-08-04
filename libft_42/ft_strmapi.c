/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:56 by ckunimur          #+#    #+#             */
/*   Updated: 2022/09/28 20:31:09 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*p;

	i = 0;
	len = ft_strlen(s);
	p = ft_calloc(len + 1, sizeof(char));
	while (i < len)
	{
		p[i] = f(i, (char)s[i]);
		i++;
	}
	return (p);
}
