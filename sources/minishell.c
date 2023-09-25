/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/25 18:18:15 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell g_minishell;

static	void	is_valid(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (exit(1));
}

int	main(int argc, char **argv, char **envp)
{
	t_config	*data;	

	is_valid(argc, argv);
	data = get_data();
	data->state = INIT;
	while (1)
	{
		if (data->state == INIT)
			init(envp);
		if (data->state == PROMPT)
			prompt();
		if (data->state == PARSER)
			parser();
		// if (data->state == BUILTINS)
		// 	execute_builtin();
        if (data->state == EXIT)
            printf("Cabô\n");
		if (data->state == EXECUTE)
			execute(envp);
		//if (data->state == EXIT)
			//exit_program(0);
	}
    free_minishell(); //coloquei fora para evitar vazamentos, pois estava dando free mais de uma vez. 
	return (0);
}
