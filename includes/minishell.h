/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:03:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/26 16:42:23 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EXIT 0
# define INIT 1
# define PROMPT 2
# define PARSER 3
# define EXECUTE 4
# define BUILTINS 5

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include "minishell.h"
# include "../libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_config
{
	char	*input;
	char	*parser;
	int		state;
}	t_config;

typedef struct	s_tokens
{
	char	**value;
	struct s_tokens *next;
} t_tokens;

typedef struct s_minishell
{
	char	**envp_copy;
	char	**export_list;
	char	**export_copy;
	int		exit_status;
	int		execute_builtin;
	t_tokens *tokens;
}	t_minishell;


//main
extern t_minishell	g_minishell;

//builtins
void	ft_pwd(void);
void	ft_cd(char **args);
void	ft_echo(char **args);
int		ft_exit(char **input_line);
void	ft_cd(char **args);
void	ft_echo(char **args);
int		env_count_var(char **envp);
char	**env_duplicate(char **envp);
void	envp_free(char ***envp_copy);
int		is_valid_export_format(char *str);
void	add_export(char *str, char ***envs, int *count);
void	print_export(char **envs);
void	ft_export(char **token_args);
void	ft_env(void);
int		execute_builtin(char **args);
int		find_var_index(char *var_name);
void	remove_var(int index);
void	ft_unset(char *var_name);
int		if_exist_remove_unset(char *token_i, int j, int length);
void	index_to_remove_env(char **envp_copy, int j);
int		is_name_unset(char *token_args);
void	copy_env_vars(char **src, char **dst, int count);
char	**add_var_to_env(char **envp_copy, const char *new_var);
void	refresh_env(char **token_args, int j);
void	ft_export(char **token_args);
int		check_and_update_var(char *token_args, int len);
int		check_var(char **token_args, int i);
int		is_valid_name(char **token_args, int i);
void	add_quotes(int i, int j);
int		execute_builtin(char **args);

//init
void	init(char **envp);

//prompt
void	prompt(void);
void	validate_prompt(t_config	*data);
int		check_quotes(char *line);
//static char	*read_line(t_config *data);

//parser
void	parser(void);
int		count_space(char *line);
void	check_direct(t_config *data);
void	check_shift(t_config *data, int space);
void	create_space(t_config *data);
void	check_pipe(t_config *data, int space);

//tokens
t_tokens *create_tokens(char **input);

//execute
void	execute(void);

//signals
void	sigquit_handler(int signal);
void	sigint_handler(int signal);
void	ctrl_d(char *input_line);

//utils
void		free_minishell(void);
t_config	*get_data(void);

#endif
