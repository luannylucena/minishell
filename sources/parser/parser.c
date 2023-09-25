
#include "../../includes/minishell.h"

// conta o número de espaços adicionais que serão 
//necessários para inserir entre os caracteres especiais <, >, e | em uma linha.
int	count_space(char *line)
{
	int	space;
	int	i;
	int	len;

	i = 0;
	space = 0;
	if(line == NULL)
		return (-1);
	len = ft_strlen(line);
	while (line[i] && i < len)
	{
		if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			space += 2;
		i++;
	}
	return (space);
}


void	check_shift(t_config *element, int space)
{
	int		i;
	int		j;
	char	*new_line; //substitui a string original em element->input após a formatação.

	i = 0;
	j = 0;
	if (element->input == NULL)
    {
        printf("Erro: element->input é NULL em check_shift\n");
        return ;
    }
	new_line = (char *)ft_calloc((ft_strlen(element->input) + space + 1), (sizeof(char)));
	if (new_line == NULL)
    {
        // Lidar com o erro de alocação de memória, se necessário
        printf("Erro de alocação de memória em check_shift\n");
        return;
    }
	while (element->input[i])
	{
		if ((element->input[i + 1] == '<' && element->input[i] != ' ' && element->input[i] != '<')
			|| (element->input[i] == '<' && element->input[i + 1] != ' ' && element->input[i + 1] != '<')
			|| (element->input[i + 1] == '>' && element->input[i] != ' ' && element->input[i] != '>')
			|| (element->input[i] == '>' && element->input[i + 1] != ' ' && element->input[i + 1] != '>'))
		{
			new_line[j++] = element->input[i++];
			new_line[j++] = '*';
		}
		else
			new_line[j++] = element->input[i++];
	}
	free(element->input);
	element->input = new_line;
}

// Se encontra aspas duplas (") ou simples ('), pula o conteúdo entre as aspas.
// Substitui espaços em branco por asteriscos (*).

void	check_pipe(t_config *element, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	//printf("elementprompt: %s\n", element->input);
	//printf("%zu", ft_strlen(element->input));
	new_line = (char *)ft_calloc(ft_strlen(element->input) + space + 1, sizeof(char));
	while (element->input[i] != '\0')
	{
		if (element->input[i] == '|')
		{
			new_line[j++] = '*';
			new_line[j++] = element->input[i++];
			new_line[j++] = '*';
		}
		else
			new_line[j++] = element->input[i++];
	}
	new_line[j] = '\0';
	free (element->input);
	element->input = new_line;
}
// realiza verificações e formatações específicas na string data->input, 
// que contém um comando do shell.
void	check_direct(t_config *element)
{
	int space;

	space = count_space(element->input);
	check_shift(element, space);
	check_pipe(element, space);
	//free(element->input);
	//element->input = NULL;
	printf("%s\n", element->input);
}

void parser(void)
{
	t_config	*element;
	char		**split_input;

	element = get_data();
	check_direct(element);
	split_input = ft_split(element->input, '*');
	g_minishell.tokens = create_tokens(split_input);
	element->state = EXECUTE;
}
