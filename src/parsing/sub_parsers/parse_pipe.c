/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:32:54 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:08:53 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_pipe_list	*new_pipe_list(t_cmd_and_args *cmd)
{
	t_pipe_list	*new_pipe_list;

	new_pipe_list = (t_pipe_list *)malloc(sizeof(t_pipe_list));
	if (!new_pipe_list)
		return (NULL);
	new_pipe_list->cmd = cmd;
	new_pipe_list->next_pipe = NULL;
	return (new_pipe_list);
}

void	parse_pipe(t_parsing_utils **ctx, t_command_line *cmd_line)
{
	t_pipe_list	*new_pipe;
	t_pipe_list	*last_pipe;

	if (cmd_line->pipe_list == NULL)
	{
		cmd_line->pipe_list = new_pipe_list((*ctx)->current_cmd);
		if (!cmd_line->pipe_list)
			return ;
	}
	new_pipe = new_pipe_list(NULL);
	if (!new_pipe)
		return ;
	last_pipe = cmd_line->pipe_list;
	while (last_pipe->next_pipe != NULL)
		last_pipe = last_pipe->next_pipe;
	last_pipe->next_pipe = new_pipe;
	(*ctx)->current_cmd = NULL;
}
