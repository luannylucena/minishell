/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:42:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/05 15:59:45 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*read_line(t_config *data)
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
		if (*str != '\0')
		{
			add_history(str);
			return(str);
		}
		else
			free(str);
	}
	return (NULL);
}

int	check_quotes(char *line)
{
	int i;
	int uniquote;
	int duoquote;

	i = 0;
	uniquote = 0;
	duoquote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34)
			duoquote++;
		if (line[i] == 39)
			uniquote++;
		i++;
	}
	return((uniquote % 2) + (duoquote % 2));
}

int	check_only_space(char *str)
{
	if(!str)
		return (0);	
	while(*str)
	{
		if(*str != ' ')
			return(1);
		str++;
	}
	return(0);
}

void	validate_prompt(t_config	*data)
{
	if(check_quotes(data->prompt))
	{
		data->state = EXIT;
		printf("aspas abertas");
		free(data->prompt);
	}
	if (check_only_space(data->prompt))
	{
		printf("foi pro parse");
		data->state = PARSE;
	}
	if (data->state == PROMPT && data->prompt)
		free(data->prompt);
	printf("passou pelo prompt");
}

void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->prompt = read_line(data);
	
	validate_prompt(data);
	
}
