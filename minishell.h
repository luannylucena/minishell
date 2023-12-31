/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:minishell.h
/*   Created: 2023/07/28 16:52:47 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/07/28 17:45:11 by lmedeiro         ###   ########.fr       */
=======
/*   Created: 2023/07/28 14:41:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/02 16:17:52 by lmedeiro         ###   ########.fr       */
>>>>>>> 0490029... enviando o signals para a branch main:signals/signals.c
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
<<<<<<< HEAD:minishell.h
=======
#include "minishell.h"
 
//
void ctrl_d(char *input_line)
{
    if(input_line == NULL)
    {
        printf("Você digitou ctrl+d, adeus!\n");
        exit(EXIT_SUCCESS);
    }
}

void sigquit_handler(int signal)
{
    printf("\rVocê pressionou Ctrl + \\, mas esse sinal foi ignorado.\n");
    rl_on_new_line();
    rl_redisplay();
    
}
>>>>>>> 0490029... enviando o signals para a branch main:signals/signals.c

void ctrl_d(char *input_line);
void ft_exit(char *input_line);
void sigquit_handler(int signal);
void sigint_handler(int signal);

#endif