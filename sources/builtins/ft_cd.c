/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:52:10 by ckunimur          #+#    #+#             */
/*   Updated: 2023/08/15 14:52:23 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void   ft_cd(char **args) //recebe um array de strings 'args'                       
{
    //nenhum argumento passado além do cd, então vamos para HOME
    if (args[1] == NULL)
    {
        const char *go_home = getenv("HOME");
        if (go_home != NULL) //Verificamos se conseguimos obter o caminho do diretório HOME (ou seja, se não é NULL)
        {
            if (chdir(go_home) != 0) //Se retornar um valor diferente de zero, significa que ocorreu um erro durante a mudança de diretório.
            {
                perror("cd");
            }
        }
        else
        {
            ft_putendl_fd("cd: could not determine home directory\n", 2);
        }
    }
    else if (args[1] != NULL && chdir(args[1]) != 0) //se a função chdir retornar um valor diferente de zero, isso significa que ocorreu um erro 
    {
        perror("cd");
    }
}