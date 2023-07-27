#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include "/libft/libft.h"

int main(int argc, char **argv, char **envp)
{
    // if(argc != 2)
    // {
    //     printf("Erro: número de argumentos excedido.\n");
    // }
    char *input_line;

    while(1)
    {
        // Exibir o prompt e aguardar um comando usando readline
        input_line = readline("minishell > ");

        // Verificar se o usuário digitou "exit" para sair do minishell
        if(strcmp(input_line, "exit") == 0) //adaptar com a Libft: ft_strcmp.
        {
            printf("Bye!\n");
            free(input_line);
            break;
        }
        if(input_line)
        {
            printf("%s\n", input_line);
            //fazer um execve aqui.
            free(input_line);
        }
        return(0);
    }
}