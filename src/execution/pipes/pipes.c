/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:52:15 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 20:53:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	init_single_pipe(int **pipefd, int index)
{
	pipefd[index] = (int *)malloc(2 * sizeof(int));
	if (!pipefd[index] || pipe(pipefd[index]) == -1)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

int	init_pipes(t_execute_ctx *ctx)
{
	int	i;

	if (ctx->num_pipes <= 0)
		return (1);
	ctx->pipefd = (int **)malloc(ctx->num_pipes * sizeof(int *));
	if (!ctx->pipefd)
		return (0);
	i = 0;
	while (i < ctx->num_pipes)
	{
		if (!init_single_pipe(ctx->pipefd, i))
			return (0);
		i++;
	}
	return (1);
}

void	close_pipes_in_child(t_execute_ctx *ctx, int current_pipe)
{
	int	i;

	i = 0;
	while (i < ctx->num_pipes)
	{
		if (i != current_pipe - 1)
			close(ctx->pipefd[i][0]);
		if (i != current_pipe)
			close(ctx->pipefd[i][1]);
		i++;
	}
}

void	execute_pipeline(t_command_line *command_line,
		t_execute_ctx *ctx, char ***envp)
{
	int	i;

	i = 0;
	ignore_signals();
	while (command_line->pipe_list)
	{
		ctx->pid[i] = fork();
		if (ctx->pid[i] == -1)
		{
			perror("fork");
			return ;
		}
		if (ctx->pid[i] == 0)
			handle_child_process(command_line, ctx, envp, i);
		close_current_pipes(ctx, i);
		command_line->pipe_list = command_line->pipe_list->next_pipe;
		i++;
	}
	wait_for_children(ctx);
	setup_signals();
}

void	close_current_pipes(t_execute_ctx *ctx, int i)
{
	if (i > 0)
	{
		close(ctx->pipefd[i - 1][0]);
		close(ctx->pipefd[i - 1][1]);
	}
}
