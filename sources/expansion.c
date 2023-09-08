/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:58:41 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/07 20:12:03 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	is_var_name(char **token_args)
// {
// 	int	j;

// 	j = 0;
// 	if (token_args[i][j] != '_' && !ft_isalpha(token_args[i][j]))
// 		return (0);
// 	j++;
// 	while (token_args[i][j] == '_' || ft_isalnum(token_args[i][j]))
// 		j++;
// 	if (!token_args[i][j] || token_args[i][j] == '=')
// 		return (1);
// 	return (0);
// }

static int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char    *find_$_position(char *input_line)
{
    while(*input_line)
    {
        if (*input_line == '\'') // Se encontrar uma aspa simples
        {
            input_line++;
            while (*input_line && *input_line != '\'') // Avança até encontrar a próxima aspa simples
                input_line++;
        }
        if (*input_line == '\"') // Se encontrar uma aspa dupla
        {
            input_line++;
            while (*input_line && *input_line != '\"') // Avança até encontrar a próxima aspa dupla
            {
                if (*input_line == '$' && (is_varname(input_line[1]) || input_line[1] == '?')) // Se encontrar um '$' seguido por um nome de variável válido ou '?' dentro das aspas duplas
                    return (input_line); // Retorna a posição do '$' encontrado
                input_line++;
            }
        }
        if (*input_line == '$' && (is_varname(input_line[1]) || input_line[1] == '?')) // Se encontrar um '$' seguido por um nome de variável válido ou '?'
            return (input_line); // Retorna a posição do '$' encontrado
        input_line++; // Avança para o próximo caractere na string
    }
    return (NULL); // Retorna NULL se nenhuma variável for encontrada
}

void	update_input(char **input_line, char *var_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input_line[0] && !var_value)
		first_part = ft_strdup("");
	else if (!*input_line[0] && var_value)
		first_part = ft_strdup(var_value);
	else if (!var_value)
		first_part = ft_strdup(*input_line);
	else
		first_part = ft_strjoin(*input_line, var_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	free(*input_line);
	*input_line = updated_input;
}

char	*var_to_value(char *var_name)
{
	char	*key;
	int		key_size;
	int		index;

	key = ft_strjoin(var_name, "=");
	key_size = ft_strlen(key);
	index = 0;
	while (g_minishell.envp[index])
	{
		if (ft_strncmp(g_minishell.envp[index], key, key_size) == 0)
		{
			free(key);
			return (ft_strdup(g_minishell.envp[index] + key_size));
		}
		index++;
	}
	free(key);
	return (""); //retorna uma string vazia para dizer que não foi encontrado.
}

void	expand_variables(char **input_line)
{
	char	*var_pos;
	char	*var_name;
	char	*var_value;
	int		size;

	var_pos = find_$_position(*input_line);
	if (var_pos)
	{
		size = 0;
		while (is_varname(var_pos[size + 1]) || var_pos[size + 1] == '?')
			size++;
		var_name = ft_substr(var_pos, 1, size);
		*var_pos = '\0';
		if (ft_strncmp(var_name, "?", 1) == 0)
			var_value = ft_itoa(g_minishell.exit_status);
		else
			var_value = var_to_value(var_name);
		update_input(input_line, var_value, (var_pos + 1 + size));
		free(var_name);
		free(var_value);
		expand_variables(input_line);
	}
}
