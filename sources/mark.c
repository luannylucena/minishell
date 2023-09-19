/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:57:01 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/18 20:06:30 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void mark_dollar(char **input_line)
{
    char *line = *input_line; // Obtém o valor apontado por input_line e atribui a line
    char *pos = line; // Inicializa um ponteiro pos para apontar para a mesma posição que line

    // Inicia um loop enquanto o caractere atual apontado por pos não for o caractere nulo (fim da string)
    while (*pos)
    {
        // Verifica se o caractere atual apontado por pos é '$' e se o próximo caractere é um nome de variável (is_varname) ou o caractere '?'.
        if (*pos == '$' && (is_varname(pos[1]) || pos[1] == '?'))
        {
            // Marca o caractere '$' como desejado, substituindo-o por um valor representado por DOLLAR_VAR.
            *pos = DOLLAR;
        }
        pos++; // Move o ponteiro pos para o próximo caractere na string
    }
}

void    mark_tilde(char **input_line)
{
    char *line = *input_line; // Obtém o valor apontado por input_line e atribui a line
    char *pos = line; // Inicializa um ponteiro pos para apontar para a mesma posição que line

    // Inicia um loop enquanto o caractere atual apontado por pos não for o caractere nulo (fim da string)
    while (*pos)
    {
        // Verifica se o caractere atual apontado por pos é '~' e se o caractere anterior (pos[-1]) é um espaço em branco.
        if (*pos == '~' && (pos == line || isspace(pos[-1])))
        {
            // Marca o caractere '~' como desejado, substituindo-o por um valor representado por TILDE_VAR.
            *pos = TILDE;
        }
        pos++; // Move o ponteiro pos para o próximo caractere na string
    }
}

void mark_special_characters(char **input_line)
{
    mark_dollar(input_line); // Chama a função mark_dollar para processar os caracteres '$' na linha
    mark_tilde(input_line); // Chama a função mark_tilde para processar os caracteres '~' na linha
    // adicionar mais chamadas de função aqui para processar outros caracteres especiais, se necessário
}
////int main()
//{
//    char *input_line = "Exemplo $VAR ~user";
//    mark_special_characters(&input_line);
//    printf("%s\n", input_line); // A saída agora conterá as marcações para '$' e '~'
//    return 0;
//}
