/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:03:34 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:11:42 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define EXIT 0
# define PROMPT 1
# define PARSE 2

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

typedef struct s_minishell{
	char	**envp_copy;
	char	**export_list;
	char	**export_copy;
	int		exit_status;
    char	*prompt;
	char	*parse;
	int		state;
}	t_minishell;

extern t_minishell g_minishell;

//main

//builtins
void	ft_pwd(void);
void	ft_cd(char **args);
void	ft_echo(char **args);
int		ft_exit(char **input_line);
void	ft_cd(char **args);
void	ft_echo(char **args);
int		env_count_var(char **envp);
char	**env_duplicate(char **envp);
void	envp_free(char **envp_copy);
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

//prompt
void	prompt(void);
void	validate_prompt(t_minishell	*data);
int		check_quotes(char *line);
static char	*read_line(t_minishell *data);

//parser
void	parser(void);
int		count_space(char *line);
void	check_direct(t_minishell *data);
void	check_shift(t_minishell *data, int space);
void	create_tokens(t_minishell *data);
void	check_pipe(t_minishell *data, int space);
void	parser(void);

//signals
void	sigquit_handler(int signal);
void	sigint_handler(int signal);
void	ctrl_d(char *input_line);

//utils
void	free_minishell(void);

#endif
