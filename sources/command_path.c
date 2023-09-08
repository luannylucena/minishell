/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:23:05 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/07 21:23:35 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *encontrar_caminho_do_comando(const char *comando) {
    char *caminho_completo = NULL;
    char *path = getenv("PATH"); // Obtenha o valor da variável de ambiente PATH

    if (path == NULL) {
        // A variável de ambiente PATH não está definida, tratamento de erro
        return NULL;
    }

    char *diretorio = strtok(path, ":"); // Divida o PATH em diretórios usando ':' como delimitador

    while (diretorio != NULL) {
        // Construa o caminho completo concatenando o diretório e o comando
        caminho_completo = (char *)malloc(strlen(diretorio) + strlen(comando) + 2); // +2 para '/' e '\0'
        if (caminho_completo == NULL) {
            // Tratamento de erro ao alocar memória
            return NULL;
        }
        sprintf(caminho_completo, "%s/%s", diretorio, comando);

        // Verifique se o caminho completo existe (é um arquivo executável)
        if (access(caminho_completo, X_OK) == 0) {
            // O caminho completo é um arquivo executável
            return caminho_completo;
        }

        free(caminho_completo); // Libere a memória alocada para o caminho
        diretorio = strtok(NULL, ":"); // Obtenha o próximo diretório do PATH
    }

    // Se o comando não foi encontrado em nenhum dos diretórios do PATH, retorne NULL
    return NULL;
}

char *command_path = encontrar_caminho_do_comando(token_args[0]);
if (command_path == NULL) {
    // Comando não encontrado, lide com isso de acordo
    // ...
} else {
    // Execute o comando externo usando execve com command_path
    execve(command_path, token_args, NULL);

    // Se o execve retornar, algo deu errado
    perror("execve"); // Trata erros do execve
    exit(EXIT_FAILURE);
}
