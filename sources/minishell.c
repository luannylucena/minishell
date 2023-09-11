/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/11 18:52:28 by ckunimur         ###   ########.fr       */
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
		if (data->state == PARSE)
			parser();
        if (data->state == EXIT)
            printf("Cabô\n");
		//if (data->state == EXECUTE)
			//execute();
		//if (data->state == EXIT)
			//exit_program();
        free_minishell(); 
	}
	return (0);
}

/*

int main(int argc, char **argv, char **envp)
{

    while (1)
    {
        (void)argv;
        (void)envp;
        if (argc != 1)
            return (1);


        char **token_args = ft_split(input_line, ' ');

        if (token_args[0] != NULL)
        {
            if (execute_builtin(token_args))
            {
                // Se for um comando built-in, continue para a próxima iteração do loop
                // Não chame free_minishell aqui
                continue;
            }

            // Caso contrário, trata o comando como um comando externo e executa
            // ... (lógica para executar comandos externos)

            // libera memória
            i = 0;
            while (token_args[i] != NULL)
            {
                free(token_args[i]);
                i++;
            }
            free(token_args);
            //adiciona ao histórico
            if (input_line)
            {
                printf("%s\n", input_line);
                if (ft_strlen(input_line) > 0)
                    add_history(input_line);
                free(input_line);
            }
        }
    }
    // Liberar memória uma vez no final do programa antes de sair
    free_minishell();
    return (0);
}
*/