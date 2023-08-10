#include "../../includes/minishell.h"

int	count_space(char *line)
{
	int space;

	space = 0;
	while (*line)
	{
		if (*line == '<' || *line == '>' || *line == '|')  
			space += 2;
		line++;
	}
	return(space);
}

char *check_direct(char *line)
{
	char *new_line;
	int space;

	space = count_space(line);
	new_line = check_shift(line, space);
	new_line = check_pipe(new_line, space);
	printf("%i\n", space);
	return(new_line);
}

char *check_shift(char *line, int space)
{
	int i;
	int j;
	char *new_line;

	i = 0;
	j = 0;
	new_line = (char *)ft_calloc((ft_strlen(line) + space + 1), (sizeof(char)));

	while (line[i])
	{
		if (line[i + 1] == '<' && (line[i] != ' ' && line[i] != '<'))
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else if (line[i] == '<' && line[i + 1] != ' ' && line[i + 1] != '<')
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else if (line[i + 1] == '>' && (line[i] != ' ' && line[i] != '>'))
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else if (line[i] == '>' && line[i + 1] != ' ' && line[i + 1] != '>')
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i++];
	}
	new_line[j] = '\0';
	return(new_line);
}	
char *check_pipe(char *line, int space)
{
	int i = 0;
	int j = 0;
	char *new_line;
	new_line = (char *)ft_calloc(ft_strlen(line) + space + 1, sizeof(char));
	printf("%s\n", new_line);
	while(line[i] != '\0')
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
	free(line);
	return(new_line);
}
void	parser(char *input_line)
{
	char *new_line;

	new_line = check_direct(input_line);
	printf("%s\n", new_line);
}
