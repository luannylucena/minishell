/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/04 16:00:38 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_config	*data;

	data = get_data();
	signal (SIGQUIT, sigquit_handler);
	signal (SIGINT, sigint_handler);
	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		if (data->state == PROMPT)
			prompt();
		if (data->state == PARSE)
			parse();
		ctrl_d(data->prompt);
		if (strcmp(data->prompt, "exit") == 0)
		{
			printf ("Bye, Bye!\n");
			free (data->prompt;
			exit (EXIT_SUCCESS);
		}
		if (data->prompt)
		{
			printf ("%s\n", data->prompt);
			
			free(data->prompt);
		}
	}
	return (0);
}
