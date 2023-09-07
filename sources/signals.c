/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:41:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:03:26 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("\rVocê pressionou Ctrl + \\, mas esse sinal foi ignorado.\n");
	rl_on_new_line();
	rl_redisplay();
	(void)signal;
}

void	sigint_handler(int signal)
{
	printf("\rVocê pressionou Ctrl + C, mas esse sinal foi ignorado.\n");
	rl_on_new_line();
	rl_redisplay();
	(void)signal;
}
