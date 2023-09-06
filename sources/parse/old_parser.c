/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:04:13 by ckunimur          #+#    #+#             */
/*   Updated: 2023/09/06 12:29:46 by ckunimur         ###   ########.fr       */
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
	free (new_line);
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
	{m
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

void	parser(char *prompt)
{
	char	**parser;
	int i;
	
	i = 0;
	parser = check_direct(prompt);
	if (check_builtins(prompt) == 0)
		printf("is BUILTINS\n");
	while(prompt[i])
	{
		printf("entrou");
		free(prompt[i++]);
	}
	free(prompt);
}
