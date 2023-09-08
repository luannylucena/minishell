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

char	*find_command_path(const char *command)
{
	char	*full_path = NULL;
	char	*path = getenv("PATH"); // Obtenha o valor da variável de ambiente PATH
	
	if (path == NULL)
	{
		// A variável de ambiente PATH não está definida, tratamento de erro
		return (NULL);
	}
	
	char *diretorio = strtok(path, ":"); // Divida o PATH em diretórios usando ':' como delimitador
	
	while (diretorio != NULL)
	{
		// Construa o caminho completo concatenando o diretório e o comando
		full_path = (char *)malloc(strlen(diretorio) + strlen(command) + 2); // +2 para '/' e '\0'
		if (full_path == NULL)
		{
			// Tratamento de erro ao alocar memória
			return (NULL);
		}
		sprintf(full_path, "%s/%s", diretorio, command);

		// Verifique se o caminho completo existe (é um arquivo executável)
		if (access(full_path, X_OK) == 0)
		{
			// O caminho completo é um arquivo executável
			return (full_path);
		}
		free(full_path); // Libere a memória alocada para o caminho
		diretorio = strtok(NULL, ":"); // Obtenha o próximo diretório do PATH
	}
	return (NULL); // Se o comando não foi encontrado em nenhum dos diretórios
}
