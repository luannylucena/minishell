/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:56:14 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/05 18:16:55 by ckunimur         ###   ########.fr       */
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
	check_pipe(&data);
	check_space(&data);
}

void	*check_shift(t_config *data, int space)
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
	return (new_line);
}

void parse(void)
{
	t_config	*data;

	data = get_data();
	printf("entrei no parse");
	check_direct(data);
}
