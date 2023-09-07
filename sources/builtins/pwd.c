/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:23:58 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 17:24:07 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	current_dir[1024];

	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		printf("%s\n", current_dir);
	else
		perror("getcwd");
}
