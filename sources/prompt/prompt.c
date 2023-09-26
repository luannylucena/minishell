#include "../../includes/minishell.h"

static char	*read_line(t_config *element)
{
	char	*str;

	str = readline("minishell$ ");
	// Se a função readline() retornar NULL, isso significa 
	// que a entrada foi encerrada (por exemplo, quando o usuário pressiona Ctrl+D), e o 
	// estado EXIT é definido em element, e a função retorna NULL.
	if (!str) 
	{
		element->state = EXIT;
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
			duoquote++; // vai iterando enquanto acha aspas e contando.
		if (line[i] == 39)
			uniquote++;
		i++;
	}
	// retorna a soma dos restos da divisão de uniquote por 2 e duoquote por 2. 
	// Isso resulta em 0 se as aspas estiverem balanceadas (número par de aspas), e 1 se 
	// houver um número ímpar de aspas abertas (desbalanceadas).
	return((uniquote % 2) + (duoquote % 2));
}

// verifica se uma string str consiste apenas em espaços em branco.
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

void	validate_prompt(t_config	*element)
{
	if(check_quotes(element->input))
	{
		element->state = EXIT;
		printf("aspas abertas");
		free(element->input);
		element->input = NULL;
	}
	if (check_only_space(element->input))
		element->state = PARSER;
	if (element->state == PROMPT && element->input)
		free(element->input);
}

void	prompt(void)
{
	t_config	*element;

	element = get_data();
	element->input = read_line(element);
	validate_prompt(element);
}
