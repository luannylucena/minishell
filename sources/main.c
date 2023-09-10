/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/09 21:34:57 by lmedeiro         ###   ########.fr       */
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
    g_minishell.envp = envp;

    while (1)
    {
        (void)argv;
        (void)envp;
        if (argc != 1)
            return (1);
        input_line = readline("minishell$ ");
        if (input_line == NULL)
            ctrl_d(input_line);
        expand_variables(&input_line); // Expande variáveis antes de verificar o comando
        char **token_args = ft_split(input_line, ' ');

        if (token_args[0] != NULL)
        {
            // Verifica se o comando é um comando built-in e o executa
            if (execute_builtin(token_args))
            {
                // Se for um comando built-in, continue para a próxima iteração do loop
                continue;
            }
            else
            {
                char *command_path = find_command_path(token_args[0]);
                if(command_path == NULL)
                {
                    // Comando não encontrado, lide com isso de acordo
                }
                else
                {
                    //fork para criar um processo filho
                    pid_t   child_pid = fork();
                    if(child_pid == -1)
                    {
                        perror("fork");
                        exit(EXIT_FAILURE);
                    } 
                    else if(child_pid == 0)
                    {
                        printf("Este é o processo filho (PID: %d)\n", getpid());
                        //processo filho. Exeute o comando externo usando execve
                        execve(command_path, token_args, NULL);

                        //se o execve retornar, algo deu errado.
                        perror("execve"); 
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        printf("Este é o processo pai (PID: %d), filho criado com PID: %d\n", getpid(), child_pid);
                        //processo pai
                        int status;
                        waitpid(child_pid, &status, 0);// Espere o processo filho terminar
                        // Lidar com status, se necessário
                    }
                    free(command_path);
                }
            }
            // Caso contrário, trata o comando como um comando externo e executa
            // ... (lógica para executar comandos externos)

            // ... (libera memória, adiciona ao histórico, etc.)
            i = 0;
            while (token_args[i] != NULL)
            {
                free(token_args[i]);
                i++;
            }
            free(token_args);
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