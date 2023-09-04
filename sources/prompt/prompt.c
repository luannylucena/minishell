/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:42:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/04 19:37:09 by ckunimur         ###   ########.fr       */
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

int	check_quotes(t_config * data, char *line)
{
	int i;
	int count;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34)
		{
			count++;
			while (line[++i] != 34 && line[i]);
		}
		else if (line[i] == 39)
		{
			count++;
			while (line[++i] != 39 && line[i]);
		}
		else if (line[i] == ' ')
			line[i] = '*';
		i++;
	}
	return(count % 2);
}

void	validate_prompt(t_config	*data)
{
	if(check_quotes)
	{
		data->state = EXIT;
		free(data);
	}
}

void	prompt(void)
{
	t_config	*data;
	char		*str;
	
	data = get_data();
	data->prompt = read_line("minishell >");
	
	validate_prompt(data);
	
}
