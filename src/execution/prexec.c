/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prexec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:43:21 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_child_process(t_command_line *command_line,
		t_execute_ctx *ctx, char ***envp, int pipe_index)
{
	reset_signals_for_child();
	handle_redirections(command_line->io_modifiers, pipe_index,
		ctx->num_pipes, ctx->pipefd);
	command_line->io_modifiers = ctx->head_io;
	close_pipes_in_child(ctx, pipe_index);
	if (is_builtin(command_line->pipe_list->cmd->args->args[0]))
		execute_builtin(&command_line->pipe_list->cmd, envp, NULL, NULL);
	else
		execute_command(&command_line->pipe_list->cmd, envp);
	exit(EXIT_FAILURE);
}

void	wait_for_children(t_execute_ctx *ctx)
{
	int	i;

	i = 0;
	while (i <= ctx->num_pipes)
	{
		waitpid(ctx->pid[i], &ctx->status, 0);
		if (WIFEXITED(ctx->status))
			g_signal_number = WEXITSTATUS(ctx->status);
		else if (WIFSIGNALED(ctx->status))
			g_signal_number = 128 + WTERMSIG(ctx->status);
		i++;
	}
}

int	allocate_pid_array(t_execute_ctx *ctx)
{
	ctx->pid = (pid_t *)malloc((ctx->num_pipes + 1) * sizeof(pid_t));
	if (!ctx->pid)
	{
		perror("malloc");
		return (0);
	}
	return (1);
}

void	pre_exec_part2(t_command_line *command_line,
		t_execute_ctx *ctx, char ***envp)
{
	t_pipe_list	*original_pipe;

	if (!init_pipes(ctx))
	{
		cleanup_execute_ctx(ctx);
		g_signal_number = EXIT_FAILURE;
		return ;
	}
	if (!allocate_pid_array(ctx))
	{
		cleanup_execute_ctx(ctx);
		return ;
	}
	execute_pipeline(command_line, ctx, envp);
	original_pipe = ctx->head_pipe;
	cleanup_execute_ctx(ctx);
	command_line->pipe_list = original_pipe;
}

void	pre_exec(t_command_line *command_line, char ***envp,
		t_char_index **head, t_dir_state *directory_state)
{
	t_execute_ctx	*ctx;

	if (!command_line->pipe_list && command_line->io_modifiers)
	{
		handle_empty_redirection(command_line->io_modifiers);
		return ;
	}
	ctx = init_execute_ctx(envp, head, directory_state);
	if (!ctx)
	{
		perror("Failed to initialize execution context");
		return ;
	}
	if (!command_line->pipe_list->next_pipe
		&& is_builtin(command_line->pipe_list->cmd->args->args[0]))
	{
		handle_single_builtin(command_line, envp, head, directory_state);
		cleanup_execute_ctx(ctx);
		return ;
	}
	init_execution(command_line, ctx);
	pre_exec_part2(command_line, ctx, envp);
}
