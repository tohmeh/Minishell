/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:47:08 by gakhoury          #+#    #+#             */
/*   Updated: 2025/03/15 01:55:35 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	free_tokens_list(t_token *head)
{
	t_token	*temp;

	while (head)
	{
		temp = head;
		head = head->next_token;
		free(temp->value);
		free(temp);
	}
}

void	free_context(t_parsing_utils *ctx)
{
	free_tokens_list(ctx->head_token);
	free(ctx);
}

void	free_io_list(t_io_modifier_list **io_list)
{
	t_io_modifier_list	*l_io;

	l_io = NULL;
	while ((*io_list))
	{
		free((*io_list)->mod->file);
		free((*io_list)->mod);
		l_io = (*io_list);
		(*io_list) = (*io_list)->next_mod;
		free(l_io);
	}
}

void	free_pipe_list(t_pipe_list **pipe_list)
{
	int			i;
	t_pipe_list	*l_pipe;

	while ((*pipe_list))
	{
		i = -1;
		if ((*pipe_list)->cmd != NULL)
		{
			if ((*pipe_list)->cmd->args != NULL)
			{
				if ((*pipe_list)->cmd->args->args != NULL)
				{
					while (++i < (*pipe_list)->cmd->args->arg_count)
						free((*pipe_list)->cmd->args->args[i]);
					free((*pipe_list)->cmd->args->args);
				}
				free((*pipe_list)->cmd->args);
			}
			free((*pipe_list)->cmd->command);
			free((*pipe_list)->cmd);
		}
		l_pipe = (*pipe_list);
		(*pipe_list) = (*pipe_list)->next_pipe;
		free(l_pipe);
	}
}
