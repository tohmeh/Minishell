/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:55:30 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 15:18:57 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	handle_heredocs(t_io_modifier_list *io_list)
{
	t_io_modifier_list	*current;
	int					stdin_backup;

	stdin_backup = setup_stdin_backup();
	if (stdin_backup == -1)
		return ;
	current = io_list;
	while (current)
	{
		if (current->mod->type == REDIR_HEREDOC)
			process_heredoc(current, stdin_backup);
		current = current->next_mod;
	}
	close(stdin_backup);
}
