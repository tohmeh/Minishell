/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:52:34 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	open_file_with_mode(const char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		perror("Failed to open file");
		g_signal_number = EXIT_FAILURE;
	}
	return (fd);
}

static void	handle_redirection_output(t_io_modifier *mod)
{
	int	fd;

	fd = open_file_with_mode(mod->file, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return ;
	close(fd);
}

static void	handle_redirection_append(t_io_modifier *mod)
{
	int	fd;

	fd = open_file_with_mode(mod->file, O_WRONLY | O_CREAT | O_APPEND);
	if (fd == -1)
		return ;
	close(fd);
}

void	handle_empty_redirection(t_io_modifier_list *io_list)
{
	t_io_modifier_list	*current;

	if (!io_list)
		return ;
	current = io_list;
	while (current)
	{
		if (current->mod->type == REDIR_OUTPUT)
			handle_redirection_output(current->mod);
		else if (current->mod->type == REDIR_APPEND)
			handle_redirection_append(current->mod);
		current = current->next_mod;
	}
	g_signal_number = 0;
}

void	handle_redirections(t_io_modifier_list *io_list, int i, int num_pipes,
		int **pipefd)
{
	int	j;

	j = 0;
	while (j < num_pipes)
	{
		if (j != i - 1)
			close(pipefd[j][0]);
		if (j != i)
			close(pipefd[j][1]);
		j++;
	}
	if (i > 0 && pipefd[i - 1][0] != -1)
		dup2(pipefd[i - 1][0], STDIN_FILENO);
	if (i < num_pipes && pipefd[i][1] != -1)
		dup2(pipefd[i][1], STDOUT_FILENO);
	redirect_input(io_list);
	redirect_output(io_list);
}
