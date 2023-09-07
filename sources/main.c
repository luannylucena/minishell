/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/07 17:16:32 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell g_minishell;

int main(int argc, char **argv, char **envp)
{
    char *input_line;
    int i;

    signal(SIGQUIT, sigquit_handler);
    signal(SIGINT, sigint_handler);
    g_minishell.envp_copy = env_duplicate(envp);
    g_minishell.export_list = env_duplicate(envp);

    while (1)
    {
        (void)argv;
        (void)envp;
        if (argc != 1)
            return (1);
        input_line = readline("minishell$ ");
        if (input_line == NULL)
            ctrl_d(input_line);

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