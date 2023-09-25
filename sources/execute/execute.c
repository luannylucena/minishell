/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:14:17 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/25 18:24:28 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char **envp)
{
	t_tokens	*tokens;
	int			pid;
	int			status;

	status = 0;
	pid = fork();
	tokens = g_minishell.tokens;
	if(pid < 0)
	{
		execve(tokens->value[0], tokens->value, envp);
	}
	waitpid(pid, &status, 0);
}