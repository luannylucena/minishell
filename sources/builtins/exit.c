/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:19:52 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/09 21:14:00 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

// void	ft_putendl_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// 	write(fd, "\n", 1);
// }

int is_number(const char *num)
{
    if (num == NULL)
        return 0;

    int i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    while (num[i])
    {
        if (num[i] < '0' || num[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int ft_exit(char **input_line)
{
    if (input_line == NULL)
    {
        fprintf(stderr, "Invalid input\n");
        return -1;
    }

    int arg_count = count_args(input_line);
    if (arg_count > 2)
    {
        fprintf(stderr, "exit: too many arguments\n");
        return -1;
    }
    if (arg_count == 1)
    {
        fprintf(stdout, "Bye!!!\n");
        free_minishell(); // Make sure to free any dynamically allocated memory
    }
    if (!is_number(input_line[1]))
    {
        fprintf(stderr, "exit: numeric argument required\n");
        return -1;
    }
    int exit_code = atoi(input_line[1]);
    free(input_line);
    exit(exit_code);
}