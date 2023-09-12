/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:50 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/11 21:18:57 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_tab_len(char **tab) {
    int contador = 0;
    
    // Percorra a matriz até encontrar um ponteiro nulo (fim da matriz).
    while (tab[contador] != NULL) {
        contador++;
    }
    
    return contador;
}

void	init(char **envp)
{
	//t_minishell	g_minishell;
	t_config	*data;
//	char		*pwd;
	
	data = get_data();
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
	g_minishell.envp_copy = env_duplicate(envp);
	g_minishell.export_list = env_duplicate(envp);
	data->state = PROMPT;
	int i = -1;
	while (++i < ft_tab_len(g_minishell.envp_copy))
	{
		free(g_minishell.envp_copy[i]);
	}
	free(g_minishell.envp_copy);

	i = -1;
	while (++i < ft_tab_len(g_minishell.export_list))
	{
		free(g_minishell.export_list[i]);
	}
	free(g_minishell.export_list);
}