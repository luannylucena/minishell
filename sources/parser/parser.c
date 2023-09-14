
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

// realiza verificações e formatações específicas na string data->prompt, 
// que contém um comando do shell.
void	check_direct(t_config *data)
{
	int space;

	space = count_space(data->prompt);
	check_shift(data, space);
	check_pipe(data, space);
	//free(data->prompt);
	//data->prompt = NULL;
	
	printf("%s\n", data->prompt);
	//create_tokens(data);
}

void	check_shift(t_config *data, int space)
{
	int		i;
	int		j;
	char	*new_line; //substitui a string original em data->prompt após a formatação.

	i = 0;
	j = 0;
	if (data->prompt == NULL)
    {
        printf("Erro: data->prompt é NULL em check_shift\n");
        return ;
    }
	new_line = (char *)ft_calloc((ft_strlen(data->prompt) + space + 1), (sizeof(char)));
	if (new_line == NULL)
    {
        // Lidar com o erro de alocação de memória, se necessário
        printf("Erro de alocação de memória em check_shift\n");
        return;
    }
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

// Se encontra aspas duplas (") ou simples ('), pula o conteúdo entre as aspas.
// Substitui espaços em branco por asteriscos (*).
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
	//return (data->prompt);
}

void	check_pipe(t_config *data, int space)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	//printf("dataprompt: %s\n", data->prompt);
	//printf("%zu", ft_strlen(data->prompt));
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

void parser(void)
{
	t_config	*data;

	data = get_data();
	//printf("entrei no parser\n");
	check_direct(data);
	data->state = PROMPT;
}
