/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:41:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/10 15:33:14 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "../includes/minishell.h"

void	ctrl_d(char *input_line)
{
	if (input_line == NULL)
	{
		printf("Você digitou ctrl+d, adeus!\n");
		exit(EXIT_SUCCESS);
	}
}

void	sigquit_handler(int signal)
{
	(void)signal;
	printf("Você pressionou Ctrl + \\, mas esse sinal foi ignorado.\n");
}

void	sigint_handler(int signal)
{
	(void)signal;
	printf("Você pressionou Ctrl + C, mas esse sinal foi ignorado.\n");
	rl_on_new_line();
	rl_redisplay();
}
