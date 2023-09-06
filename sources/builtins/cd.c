/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:09:09 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:09:25 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char **args)
{
	char	*go_home;

	if (args[1] == NULL)
	{
		go_home = getenv("HOME");
		if (go_home != NULL)
		{
			if (chdir(go_home) != 0)
				perror("cd");
		}
		else
			ft_putendl_fd("cd: could not determine home directory\n", 2);
	}
	else if (args[1] != NULL && chdir(args[1]) != 0)
		perror("cd");
}
