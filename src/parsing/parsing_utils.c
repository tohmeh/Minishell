/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:49:39 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:10:47 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_command_line	*new_command_line(void)
{
	t_command_line	*new_cmd_line;

	new_cmd_line = (t_command_line *)malloc(sizeof(t_command_line));
	if (!new_cmd_line)
		return (NULL);
	new_cmd_line->pipe_list = NULL;
	new_cmd_line->io_modifiers = NULL;
	return (new_cmd_line);
}
