/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:24:37 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:32:52 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_name_unset(char *token_args)
{
	int	j;

	j = 0;
	if (token_args[j] != '_' && !ft_isalpha(token_args[j]))
		return (0);
	j++;
	while (token_args[j] == '_' || ft_isalnum(token_args[j]))
		j++;
	if (!token_args[j] || token_args[j] == '=')
		return (1);
	return (0);
}

void	index_to_remove_env(char **envp_copy, int j)
{
	while (envp_copy[j])
	{
		free(envp_copy[j]);
		envp_copy[j] = ft_strdup(envp_copy[j + 1]);
		if (!envp_copy[j][0])
		{
			free(envp_copy[j]);
			envp_copy[j] = NULL;
		}
		j++;
	}
}

int	if_exist_remove_unset(char *token_i, int j, int length)
{
	if (!ft_strncmp(g_minishell.envp_copy[j], token_i, length)
		&& (!g_minishell.envp_copy[j][length]
		|| g_minishell.envp_copy[j][length] == '='))
	{
		remove_env_i(g_minishell.envp_copy, j);
		return (1);
	}
	return (0);
}
