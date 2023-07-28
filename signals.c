/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:41:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/07/28 17:11:34 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "minishell.h"


void ctrl_d(char *input_line)
{
    if(input_line == NULL)
    {
        printf("Você digitou ctrl+d, adeus!\n");
        exit(EXIT_SUCCESS);
    }
}

void ft_exit(char *input_line)
{
    if(strcmp(input_line, "exit") == 0)
    {
        printf("Bye, Bye!\n");
        free(input_line);
        exit(EXIT_SUCCESS);
    }
}

void sigquit_handler(int signal)
{
    printf("Você pressionou Ctrl + \\, mas esse sinal foi ignorado.\n");
}