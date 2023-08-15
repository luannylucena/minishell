/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:04:13 by ckunimur          #+#    #+#             */
/*   Updated: 2023/08/15 15:15:30 by ckunimur         ###   ########.fr       */
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

char	**check_direct(char *line)
{
	char	*new_line;
	char	**tokens = NULL;
	int		space;

	space = count_space(line);
	new_line = check_shift(line, space);
	new_line = check_pipe(new_line, space);
	new_line = check_quotes(new_line);
	tokens = ft_split(new_line, '*');
	return (tokens);
}

char	*check_shift(char *line, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = (char *)ft_calloc((ft_strlen(line) + space + 1), (sizeof(char)));
	while (line[i])
	{
		if ((line[i + 1] == '<' && line[i] != ' ' && line[i] != '<')
			|| (line[i] == '<' && line[i + 1] != ' ' && line[i + 1] != '<')
			|| (line[i + 1] == '>' && line[i] != ' ' && line[i] != '>')
			|| (line[i] == '>' && line[i + 1] != ' ' && line[i + 1] != '>'))
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i++];
	}
	return (new_line);
}

char	*check_pipe(char *line, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = (char *)ft_calloc(ft_strlen(line) + space + 1, sizeof(char));
	while (line[i] != '\0')
	{
		if (line[i] == '|')
		{
			new_line[j++] = ' ';
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i++];
	}
	new_line[j] = '\0';
	free (line);
	return (new_line);
}

char	*check_quotes(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34)
			while (line[++i] != 34 && line[i]);
		else if (line[i] == 39)
			while (line[++i] != 39 && line[i]);
		else if (line[i] == ' ')
			line[i] = '*';
		i++;
	}
	return (line);
}

int check_builtins(char **tokens)
{
	if (ft_strncmp(tokens[0], "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(tokens[0], "cd", 2) == 0)
		ft_cd(tokens);
	else if (ft_strncmp(tokens[0], "exit", 4) == 0)
		ft_exit(tokens);
	else if (ft_strncmp(tokens[0], "echo", 4) == 0)
		ft_echo(tokens);
	else
		return (1);
	return (0);
}

void	parser(char *input_line)
{
	char	**tokens;
	int i;
	
	i = 0;
	tokens = check_direct(input_line);
	if (check_builtins(tokens) == 0)
		printf("is BUILTINS\n");
}
