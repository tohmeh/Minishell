/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:31:45 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	parse_io_modifier(t_parsing_utils **ctx, t_command_line *cmd_line,
		t_token **current_token)
{
	t_io_modifier	*io_mod;

	(void)ctx;
	io_mod = create_io_modifier(*current_token);
	if (!is_io_modifier_valid(*current_token))
	{
		g_signal_number = 2;
		free(io_mod);
		return ;
	}
	(*current_token) = (*current_token)->next_token;
	io_mod->file = ft_strdup((*current_token)->value);
	add_modifier_to_list(cmd_line, io_mod);
}
