/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:32:25 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:08:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	parse_command(t_parsing_utils **ctx, t_command_line *cmd_line,
		t_token *current_token)
{
	t_pipe_list	*l_pipe;

	(*ctx)->current_cmd = (t_cmd_and_args *)malloc(sizeof(t_cmd_and_args));
	(*ctx)->current_cmd->command = ft_strdup(current_token->value);
	(*ctx)->current_cmd->args = (t_arg_list *)malloc(sizeof(t_arg_list));
	(*ctx)->current_cmd->args->arg_count = 1;
	(*ctx)->current_cmd->args->args = (char **)malloc(sizeof(char *) * 2);
	(*ctx)->current_cmd->args->args[0]
		= ft_strdup((*ctx)->current_cmd->command);
	(*ctx)->current_cmd->args->args[1] = NULL;
	l_pipe = cmd_line->pipe_list;
	if (l_pipe == NULL)
		cmd_line->pipe_list = new_pipe_list((*ctx)->current_cmd);
	else
	{
		while (l_pipe->next_pipe != NULL)
			l_pipe = l_pipe->next_pipe;
		l_pipe->cmd = ((*ctx)->current_cmd);
	}
}
