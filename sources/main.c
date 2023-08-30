/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/30 18:25:10 by ckunimur         ###   ########.fr       */
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
		// if (strcmp(input_line, "exit") == 0)
		// {
		// 	printf ("Bye, Bye!\n");
		// 	free (input_line);
		// 	exit (EXIT_SUCCESS);
		// }
		// if (input_line)
		// {
		// 	printf ("%s\n", input_line);
		// 	
		// 	free(input_line);
		// }
	}
	return (0);
}
