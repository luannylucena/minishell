/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:32:48 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/15 15:32:56 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_echo(char **args)
{
    int i;
    int add_newline; //flag para adiconar quebra de linha
    
    i = 1;
    add_newline = 1;
    
    // Verifica se a primeira argumento é a flag -n
    if (args[i] != NULL && strcmp(args[i], "-n") == 0)
    {
        add_newline = 0; // Desativa a adição de quebra de linha. Se for 1, ativa.
        i++; // Avança para o próximo argumento
    }

    while (args[i] != NULL)
    {
        printf("%s", args[i]);
        if (args[i + 1] != NULL)
            printf(" ");
        i++;
    }
    if (add_newline) //
        printf("\n");
}