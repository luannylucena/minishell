/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:29:26 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/25 18:10:42 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens *create_tokens(char **input)
{
    t_tokens *head = NULL; // Cabeça da lista encadeada de tokens
    t_tokens *current = NULL; // Ponteiro para o último token

    while (*input)
	{
    	t_tokens *newToken = (t_tokens *)malloc(sizeof(t_tokens));
        if (newToken == NULL)
            return NULL;

        newToken->value = ft_split(*input, ' ');
        newToken->next = NULL;

        if (head == NULL) {
            head = newToken;
            current = newToken;
        } else {
            current->next = newToken;
            current = current->next;
        }
        input++;
    }
	return head;
}