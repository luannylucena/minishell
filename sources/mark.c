// Marca o caractere '$' em contextos específicos
void mark_dollar(char **input_line)
{
    char *line = *input_line;
    char *pos = line;
    while (*pos)
    {
        if (*pos == '$' && (is_varname(pos[1]) || pos[1] == '?'))
        {
            // Marca o caractere '$' como desejado (por exemplo, DOLLAR_VAR)
            *pos = DOLLAR_VAR;
        }
        pos++;
    }
}

// Marca o caractere '~' em contextos específicos
void mark_tilde(char **input_line)
{
    char *line = *input_line;
    char *pos = line;
    while (*pos)
    {
        if (*pos == '~' && (pos == line || isspace(pos[-1])))
        {
            // Marca o caractere '~' como desejado (por exemplo, TILDE_VAR)
            *pos = TILDE_VAR;
        }
        pos++;
    }
}

// Função principal para marcar caracteres especiais
void mark_special_characters(char **input_line)
{
    mark_dollar(input_line);
    mark_tilde(input_line);
    // Adicione mais chamadas de função aqui para marcar outros caracteres especiais, se necessário
}

////int main()
//{
//    char *input_line = "Exemplo $VAR ~user";
//    mark_special_characters(&input_line);
//    printf("%s\n", input_line); // A saída agora conterá as marcações para '$' e '~'
//    return 0;
//}
