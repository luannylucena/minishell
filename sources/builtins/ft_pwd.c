#include "../../includes/minishell.h"

void ft_pwd()
{
	char current_dir[1024];

	if(getcwd(current_dir, sizeof(current_dir)) != NULL)
		printf("%s\n", current_dir);
	else
		perror("getcwd");
}