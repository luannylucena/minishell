/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/07/28 17:10:47 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char *input_line;

    while(1)
    {
        // Exibir o prompt e aguardar um comando usando readline
        input_line = readline("minishell > ");

        // Verificar se o usuário digitou CTRL+D
        ctrl_d(input_line);
        
        // Verificar se o usuário digitou "exit" para sair do minishell
        ft_exit(input_line);

        // Verificar se o usuário digitou (CTRL+ \) /
        signal(SIGQUIT, sigquit_handler);

        
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