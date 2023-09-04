/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:42:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/04 19:28:25 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*read_line(t_config *data)
{
	char	*str;

	str = readline("Minishell >");
	if (!str)
	{
		data->state = EXIT;
		return(NULL);
	}
	else
	{
		if (*str == "\0")
		{
			add_history(str);
			return(str);
		}
		else
			free(str);
	}
	return(NULL);
}

void	validate_prompt(t_config	*data)
{
	
}

void	prompt(void)
{
	t_config	*data;
	char		*str;
	
	data = get_data();
	data->prompt = read_line("minishell >");
	
	validate_prompt(data);
	
}
