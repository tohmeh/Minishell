/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:34:25 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:09:11 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	parse_word(t_parsing_utils **ctx, t_command_line *cmd_line,
		t_token *current_token)
{
	if (((*ctx)->current_cmd))
	{
		(*ctx)->current_cmd->args->arg_count++;
		add_new_row(&(*ctx)->current_cmd->args->args,
			((*ctx)->current_cmd->args->arg_count));
		(*ctx)->current_cmd->args->args[(*ctx)->current_cmd->args->arg_count
			- 1] = ft_strdup(current_token->value);
		(*ctx)->current_cmd
			->args->args[(*ctx)->current_cmd->args->arg_count] = NULL;
	}
	else
	{
		(*ctx)->current_cmd = (t_cmd_and_args *)malloc(sizeof(t_cmd_and_args));
		(*ctx)->current_cmd->command = NULL;
		(*ctx)->current_cmd->args = (t_arg_list *)malloc(sizeof(t_arg_list));
		(*ctx)->current_cmd->args->arg_count = 1;
		(*ctx)->current_cmd->args->args = (char **)malloc(sizeof(char *) * 2);
		(*ctx)->current_cmd->args->args[0] = ft_strdup(current_token->value);
		(*ctx)->current_cmd->args->args[1] = NULL;
		if (cmd_line->pipe_list == NULL)
			cmd_line->pipe_list = new_pipe_list((*ctx)->current_cmd);
	}
}
