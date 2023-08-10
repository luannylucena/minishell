/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/10 15:31:59 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input_line;

	signal (SIGQUIT, sigquit_handler);
	signal (SIGINT, sigint_handler);
	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		input_line = readline("minishell > ");
		parser(input_line);
		ctrl_d(input_line);
		if (strcmp(input_line, "exit") == 0)
		{
			printf ("Bye, Bye!\n");
			free (input_line);
			exit (EXIT_SUCCESS);
		}
		if (input_line)
		{
			printf ("%s\n", input_line);
			if (ft_strlen(input_line) > 0)
				add_history(input_line);
			free(input_line);
		}
	}
	return (0);
}
