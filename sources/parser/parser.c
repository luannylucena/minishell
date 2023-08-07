#include "../../includes/minishell.h"

int	count_space(char *line)
	int space;
	int i;

	i = 0;
	space = 0;
	while (line[i])
	{
		if ((line[i] == '<' && (line[i + 1] != ' ' || line[i - 1] != ' ' || line[i + 1] != '<' || line[i - 1] != '<')) ||
				(line[i] == '>' && (line[i + 1] != ' ' || line[i - 1] != ' ' || line[i + 1] != '>' || line[i - 1] != '>')) ||
					(line[i] == '|' && (line[i + 1] != ' ' || line[i - 1] != ' ')))
			space += 2;
		i++;
	}
	return(space);
}

char *check_space(char *line)
{

	int i;
	char *cmd;
	int space;
	int j;

	j = 0;
	i = 0;
	space = count_space(line);
	cmd = (char *)ft_calloc((strlen(line) + space + 1), (sizeof(char)));
	while (line[i])
	{
		if (line[i + 1] == '<' && line[i] != ' ' && line[i] != '<') 
		{	
			cmd[j++] = line[i++];
			cmd[j++] = ' ';
		}
		else if (line[i + 1] == '>' && line[i] != ' ' && line[i] != '>') 
		{	
			cmd[j++] = line[i++];
			cmd[j++] = ' ';
		}
		else if (line[i] == '<' && line[i + 1] != ' ' && line[i + 1] != '<' && line[i - 2] != '<') 
		{	
			cmd[j++] = line[i++];
			cmd[j++] = ' ';
		}
		else if (line[i] == '>' && line[i + 1] != ' ' && line[i + 1] != '<' && line[i - 2] != '>') 
		{	
			cmd[j++] = line[i++];
			cmd[j++] = ' ';
		}
		else if (line[i] == '|' && line[i + 1] != ' ')
		{
			cmd[j++] = line[i++];
			cmd[j] = ' ';
		}
		else if (line[i + 1] == '|' && line[i] != ' ')
		{
			cmd[j++] = line[i++];
			cmd[j++] = ' ';
			if (line[i] == '|' && line[i + 1] != ' ')
				cmd[j + 1] = ' ';
		}
		cmd[j++] = line[i++];
	}
	printf("%i\n", space);
	cmd[j] = '\0';
	return(cmd);
}

void	parser(char *input_line)
{
	char *cmd;

	cmd = check_space(input_line);
	printf("%s\n", cmd);
}
