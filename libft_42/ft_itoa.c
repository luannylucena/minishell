/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:40:54 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:48 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int				l;
	unsigned int	nbr;

	l = 1;
	nbr = n;
	if (n < 0)
	{
		l++;
		nbr = n * -1;
	}
	while (nbr > 9)
	{
		nbr = (nbr / 10);
		if (nbr != 0)
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int				l;
	char			*p;
	unsigned int	nbr;

	nbr = n;
	l = ft_intlen(n);
	p = (char *)ft_calloc(l + 1, sizeof(char));
	if (!p)
		return (0);
	if (n < 0)
	{
		nbr = n * -1;
		p[0] = '-';
	}
	while (l - 1 >= 0 && p[l - 1] == '\0')
	{
		p[l - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		l--;
	}
	return (p);
}
