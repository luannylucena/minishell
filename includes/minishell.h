/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:47 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/08/07 15:10:12 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "../libft_42/libft.h"

void	ctrl_d(char *input_line);
void	ft_exit(char *input_line);
void	sigquit_handler(int signal);
void	sigint_handler(int signal);
void	parser(char *input_line);
char	*check_space(char *line);
int		count_space(char *line);

#endif