#include "../../includes/minishell.h"

char *check_space(char *line)
{

	int i;
	char *test;
	int space;
	int j;

	j = 0;
	i = 0;
	space = 0;
	while (line[i])
	{
		if ((line[i] == '<' && (line[i + 1] != ' ' || line[i - 1] != ' ' || line[i + 1] != '<' || line[i - 1] != '<')) ||
				(line[i] == '>' && (line[i + 1] != ' ' || line[i - 1] != ' ' || line[i + 1] != '>' || line[i - 1] != '>')) ||
					(line[i] == '|' && (line[i + 1] != ' ' || line[i - 1] != ' ')))
			space += 1;
		i++;
	}
	test = (char *)malloc((strlen(line) + space + 1) * (sizeof(char *)));
	i = 0;
	while (line[i])
	{
		if (line[i + 1] == '<' && line[i] != ' ' && line[i] != '<') 
		{	
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		else if (line[i + 1] == '>' && line[i] != ' ' && line[i] != '>') 
		{	
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		else if (line[i] == '<' && line[i + 1 ] != ' ' && line[i - 2] != '<') 
		{	
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		else if (line[i] == '>' && line[i + 1] != ' ' && line[i - 2] != '>') 
		{	
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		else if (line[i + 1] == '|' && line[i] != ' ')
		{
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		else if (line[i] == '|' && line[i + 1] != ' ')
		{
			test[j++] = line[i++];
			test[j++] = ' ';
		}
		test[j++] = line[i++];
	}
	printf("%i\n", space);
	test[j] = '\0';
	return(test);
}

void	parser(char *input_line)
{
	char *cmd;

	cmd = check_space(input_line);
	printf("%s\n", cmd);
}
