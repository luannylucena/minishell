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
	new_line = check_shift(line);
	new_line = check_pipe(new_line);
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
		if (line[i + 1] == '<' && line[i] != ' ' || line[i] != '<')
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
		if (line[i] == '<' && line[i + 1] != ' ' || line[i + 1] != '<')
		{
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
		}
	}
	return(new_line);
}	
char *check_pipe(char *new_line)
{
	char *new_line;
	new_line = (char *)ft_calloc(ft_strlen(new_line), sizeof(char));
	printf("%s\n", new_line);
	return(new_line);
}
void	parser(char *input_line)
{
	char *new_line;

	new_line = check_direct(input_line);

}
