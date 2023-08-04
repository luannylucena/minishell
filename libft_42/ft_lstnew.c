/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:27:00 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/03 21:54:39 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*bonus;

	bonus = (t_list *)ft_calloc(1, sizeof(t_list));
	if (bonus == NULL)
		return (NULL);
	bonus->content = content;
	bonus->next = NULL;
	return (bonus);
}
