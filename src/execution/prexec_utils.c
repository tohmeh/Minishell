/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prexec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:09:23 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 20:54:38 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_execute_ctx	*init_execute_ctx(char ***envp, t_char_index **head,
		t_dir_state *dir_state)
{
	t_execute_ctx	*ctx;

	ctx = malloc(sizeof(t_execute_ctx));
	if (!ctx)
		return (NULL);
	ctx->stdinput = dup(STDIN_FILENO);
	ctx->stdoutput = dup(STDOUT_FILENO);
	ctx->num_pipes = 0;
	ctx->pipefd = NULL;
	ctx->pid = NULL;
	ctx->head_pipe = NULL;
	ctx->head_io = NULL;
	ctx->envp = envp;
	ctx->env_head = head;
	ctx->dir_state = dir_state;
	ctx->status = 0;
	return (ctx);
}

void	cleanup_pipes(t_execute_ctx *ctx)
{
	int	i;

	if (!ctx->pipefd)
		return ;
	i = 0;
	while (i < ctx->num_pipes)
	{
		if (ctx->pipefd[i])
		{
			if (ctx->pipefd[i][0] != -1)
				close(ctx->pipefd[i][0]);
			if (ctx->pipefd[i][1] != -1)
				close(ctx->pipefd[i][1]);
			free(ctx->pipefd[i]);
		}
		i++;
	}
	free(ctx->pipefd);
}

void	cleanup_std_streams(t_execute_ctx *ctx)
{
	if (ctx->pid)
		free(ctx->pid);
	if (ctx->stdinput != -1)
	{
		dup2(ctx->stdinput, STDIN_FILENO);
		close(ctx->stdinput);
	}
	if (ctx->stdoutput != -1)
	{
		dup2(ctx->stdoutput, STDOUT_FILENO);
		close(ctx->stdoutput);
	}
}

void	cleanup_execute_ctx(t_execute_ctx *ctx)
{
	if (!ctx)
		return ;
	cleanup_pipes(ctx);
	cleanup_std_streams(ctx);
	free(ctx);
}

void	init_execution(t_command_line *command_line, t_execute_ctx *ctx)
{
	ctx->head_pipe = command_line->pipe_list;
	ctx->head_io = command_line->io_modifiers;
	ctx->num_pipes = get_num_pipes(command_line);
	if (ctx->head_io)
		handle_heredocs(ctx->head_io);
}
