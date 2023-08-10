/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/10 15:04:10 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input_line;
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
	(void)argc;
	(void)argv;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:47 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/10 15:02:53 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	(void)envp;
	while(1)
	{
		// Exibir o prompt e aguardar um comando usando readline
		input_line = readline("minishell > ");

		parser(input_line);
		// Verificar se o usuário digitou CTRL+D
		ctrl_d(input_line);
		
		// Verificar se o usuário digitou "exit" para sair do minishell
		if(strcmp(input_line, "exit") == 0)
		{
			printf("Bye, Bye!\n");
			free(input_line);
			exit(EXIT_SUCCESS);
		}
		if(input_line)
		{
			printf("%s\n", input_line);
			// Adicionando o comando ao histórico do readline
			if (strlen(input_line) > 0) //adaptar ao ft_strlen
			{
				add_history(input_line);
			}
			free(input_line);
		}
	}
	return(0);
}