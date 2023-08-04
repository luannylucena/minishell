/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:20:56 by coder             #+#    #+#             */
/*   Updated: 2022/09/19 21:00:15 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] && little[j] && k < len)
				if (big[k++] != little[j++])
					break ;
			if (little[j] == '\0' && big[--k] == little[--j])
				return (&((char *)big)[i]);
		}
		i++;
	}
	return ((void *)0);
}
