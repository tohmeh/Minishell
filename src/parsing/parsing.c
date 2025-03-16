/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:20:33 by gakhoury          #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_command_line	*parse_tokens(t_parsing_utils **ctx)
{
	t_command_line	*cmd_line;
	t_token			*current_token;

	if (!validate_syntax((*ctx)->head_token))
	{
		g_signal_number = 2;
		return (NULL);
	}
	cmd_line = new_command_line();
	if (!cmd_line)
		return (NULL);
	current_token = (*ctx)->head_token;
	while (current_token)
	{
		if (current_token->type == COMMAND && !(*ctx)->current_cmd)
			parse_command(ctx, cmd_line, current_token);
		else if (current_token->type == PIPE)
			parse_pipe(ctx, cmd_line);
		else if (is_redirect_token(current_token->type))
			parse_io_modifier(ctx, cmd_line, &current_token);
		else
			parse_word(ctx, cmd_line, current_token);
		current_token = current_token->next_token;
	}
	return (cmd_line);
}
