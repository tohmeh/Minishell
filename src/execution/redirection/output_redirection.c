/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:53:36 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	open_redirect_file(t_io_modifier *mod)
{
	if (mod->type == REDIR_OUTPUT)
		return (open(mod->file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (mod->type == REDIR_APPEND)
		return (open(mod->file, O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (-1);
}

static void	handle_redirect_error(const char *error_msg)
{
	perror(error_msg);
	g_signal_number = EXIT_FAILURE;
	exit(g_signal_number);
}

static void	perform_redirection(int fd)
{
	if (fd == -1)
		handle_redirect_error("Failed to open file");
	if (dup2(fd, STDOUT_FILENO) == -1)
		handle_redirect_error("Failed to redirect output");
	close(fd);
}

static void	process_redirect_node(t_io_modifier *mod)
{
	int	fd;

	if (mod->type == UNKNOWN)
		handle_redirect_error("Unsupported redirection type");
	if (mod->type == REDIR_OUTPUT || mod->type == REDIR_APPEND)
	{
		fd = open_redirect_file(mod);
		perform_redirection(fd);
	}
}

void	redirect_output(t_io_modifier_list *io_list)
{
	while (io_list)
	{
		if (io_list->mod->file)
			process_redirect_node(io_list->mod);
		io_list = io_list->next_mod;
	}
}
