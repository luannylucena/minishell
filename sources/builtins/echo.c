/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:09:51 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:04 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **args)
{
	int	i;
	int	add_newline;

	i = 1;
	add_newline = 1;
	if (args[i] != NULL && ft_strncmp(args[i], "-n", 2) == 0)
	{
		add_newline = 0;
		i++;
	}
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (add_newline)
		printf("\n");
}
