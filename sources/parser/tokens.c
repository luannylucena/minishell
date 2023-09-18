/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:29:26 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/18 19:00:47 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*create_tokens(t_tokens *head, char **input)
{
	int i;
	
	i = 0;
	t_tokens *new_token = (t_tokens *)ft_calloc(sizeof(t_tokens), 1);
	if (new_token == NULL)
		return(head);
	new_token->token = ft_strdup(input[0]);
	
	
}