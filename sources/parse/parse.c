/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:56:14 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/06 12:30:15 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_space(char *line)
{
	int	space;

	space = 0;
	while (*line)
	{
		if (*line == '<' || *line == '>' || *line == '|')
			space += 2;
		line++;
	}
	return (space);
}

void	check_direct(t_config *data)
{
	int space;

	space = count_space(data->prompt);
	check_shift(&data, space);
	check_pipe(&data, space);
	create_tokens(&data);
}

void	check_shift(t_config *data, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = (char *)ft_calloc((ft_strlen(data->prompt) + space + 1), (sizeof(char)));
	while (data->prompt[i])
	{
		if ((data->prompt[i + 1] == '<' && data->prompt[i] != ' ' && data->prompt[i] != '<')
			|| (data->prompt[i] == '<' && data->prompt[i + 1] != ' ' && data->prompt[i + 1] != '<')
			|| (data->prompt[i + 1] == '>' && data->prompt[i] != ' ' && data->prompt[i] != '>')
			|| (data->prompt[i] == '>' && data->prompt[i + 1] != ' ' && data->prompt[i + 1] != '>'))
		{
			new_line[j++] = data->prompt[i++];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = data->prompt[i++];
	}
	free(data->prompt);
	data->prompt = new_line;
}

void	create_tokens(t_config *data)
{
	int i;

	i = 0;
	while (data->prompt[i] != '\0')
	{
		if (data->prompt[i] == 34)
			while (data->prompt[++i] != 34 && data->prompt[i]);
		else if (data->prompt[i] == 39)
			while (data->prompt[++i] != 39 && data->prompt[i]);
		else if (data->prompt[i] == ' ')
			data->prompt[i] = '*';
		i++;
	}
	return (data->prompt);
}

void	check_pipe(t_config *data, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = (char *)ft_calloc(ft_strlen(data->prompt) + space + 1, sizeof(char));
	while (data->prompt[i] != '\0')
	{
		if (data->prompt[i] == '|')
		{
			new_line[j++] = ' ';
			new_line[j++] = data->prompt[i++];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = data->prompt[i++];
	}
	new_line[j] = '\0';
	free (data->prompt);
	data->prompt = new_line;
}

void parse(void)
{
	t_config	*data;

	data = get_data();
	printf("entrei no parse");
	check_direct(data);
}
