
#include "../includes/minishell.h"

int	find_var_index(char *var_name)
{
	int	i;

	i = 0;
	while (g_minishell.envp_copy[i] != NULL)
	{
		if (ft_strncmp(g_minishell.envp_copy[i]
				, var_name, ft_strlen(var_name)) == 0
			&& (g_minishell.envp_copy[i][ft_strlen(var_name)] == '='
			|| g_minishell.envp_copy[i][ft_strlen(var_name)] == '\0'))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	remove_var(int index)
{
	int	i;

	if (index == -1)
		return ;
	free(g_minishell.envp_copy[index]);
	i = index;
	while (g_minishell.envp_copy[i] != NULL)
	{
		g_minishell.envp_copy[i] = g_minishell.envp_copy[i + 1];
		i++;
	}
}

void	ft_unset(char *var_name)
{
	int	index;

	index = find_var_index(var_name);
	remove_var(index);
}