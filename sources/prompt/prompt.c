/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:42:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/08/30 18:24:24 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->prompt = readline("minishell > ");
	if (ft_strlen(data->prompt) > 0)
		add_history(data->prompt);
		data->state = PARSE;
}
