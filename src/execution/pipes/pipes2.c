/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:55:50 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 20:56:11 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../minishell.h"

int	get_num_pipes(t_command_line *command_node)
{
	t_pipe_list	*pipe_node;
	int			i;

	if (!command_node || !command_node->pipe_list)
		return (0);
	i = 0;
	pipe_node = command_node->pipe_list;
	while (pipe_node != NULL)
	{
		pipe_node = pipe_node->next_pipe;
		if (pipe_node)
			i++;
	}
	return (i);
}
