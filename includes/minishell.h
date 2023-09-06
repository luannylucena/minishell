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
# include "../libft/libft.h" //olhar a diferença e ver a melhor

// typedef struct	s_config
// {
// 	char	*prompt;
// 	char	*parse;
// 	int		state;
// }	t_config;

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

void	    ctrl_d(char *input_line);
int		    ft_exit(char **input_line);
void	    sigquit_handler(int signal);
void	    sigint_handler(int signal);
void	    parse(void);
char	    *check_space(char *line);
int		    count_space(char *line);
char	    **check_direct(char *line);
char	    *check_pipe(char *line, int space);
char	    *check_shift(char *line, int space);
int		    check_quotes(char *line);
void	    ft_pwd(void);
void	    ft_cd(char **args);
void	    ft_echo(char **args);
int		    ft_exit(char **input_line);
void	    prompt(void);
t_minishell *get_data(void);
void	    validate_prompt(t_config	*data);
int	        check_only_space(char *str);
void	    ft_pwd(void);
void	    ft_cd(char **args);
void	    ft_echo(char **args);
int		    env_count_var(char **envp);
char	    **env_duplicate(char **envp);
void	    envp_free(char **envp_copy);
int		    is_valid_export_format(char *str);
void	    add_export(char *str, char ***envs, int *count);
void	    print_export(char **envs);
void	    ft_export(char **token_args);
void	    ft_env(void);
int		    execute_builtin(char **args);
int		    update_when_exists(char *token_args, int len);
int		    check_if_exists_exp(char **token_args, int i);
int		    check_isname_exp(char **token_args, int i);
void	    update_env(char **token_args, int j);
void	    remove_env_i(char **envp_copy, int j);
int		    remove_if_exists(char *token_i, int j, int length);
void	    ft_unset(char *var_name);
void	    print_quotes(int i, int j);
void	    copy_env_vars(char **src, char **dst, int count);
void	    free_minishell(void);

#endif