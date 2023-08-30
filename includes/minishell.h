/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:03:16 by ckunimur          #+#    #+#             */
/*   Updated: 2023/08/30 18:25:59 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../libft_42/libft.h"

typedef struct	s_config
{
	char	*prompt;
	char	*parse;
	char	*state;
}	t_config;

# define PROMPT 1;
# define PARSE 2;

void	ctrl_d(char *input_line);
int		ft_exit(char **input_line);
void	sigquit_handler(int signal);
void	sigint_handler(int signal);
void	parse(void);
char	*check_space(char *line);
int		count_space(char *line);
char	**check_direct(char *line);
char	*check_pipe(char *line, int space);
char	*check_shift(char *line, int space);
char	*check_quotes(char *line);
void	ft_pwd();
void	ft_cd(char **args);
void	ft_echo(char **args);
int		ft_exit(char **input_line);
void	prompt(void);
t_config *get_data(void);

#endif
