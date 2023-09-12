/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:23:10 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/11 21:45:56 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_minishell(void)
{
	// if (g_minishell.envp_copy != NULL)
	// {
	// 	envp_free(&g_minishell.envp_copy);
	// 	g_minishell.envp_copy = NULL;
	// }
	// if (g_minishell.export_list != NULL)
	// {
	// 	envp_free(&g_minishell.export_list);
	// 	g_minishell.export_list = NULL;
	// }
	rl_clear_history();
	exit(EXIT_SUCCESS);
}
