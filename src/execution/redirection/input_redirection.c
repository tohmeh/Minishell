/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:51:33 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	handle_input_redirection(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open input file");
		g_signal_number = EXIT_FAILURE;
		exit(g_signal_number);
	}
	return (fd);
}

static void	handle_unknown_redirection(void)
{
	perror("Unsupported redirection type");
	g_signal_number = EXIT_FAILURE;
	exit(g_signal_number);
}

static void	redirect_fd(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Failed to redirect input");
		g_signal_number = EXIT_FAILURE;
		exit(g_signal_number);
	}
	close(fd);
}

static int	get_redirection_fd(t_io_modifier *mod)
{
	if (mod->type == REDIR_INPUT)
		return (handle_input_redirection(mod->file));
	else if (mod->type == UNKNOWN)
		handle_unknown_redirection();
	return (-1);
}

void	redirect_input(t_io_modifier_list *io_list)
{
	int	fd;

	while (io_list)
	{
		if (!io_list->mod->file)
		{
			io_list = io_list->next_mod;
			continue ;
		}
		fd = get_redirection_fd(io_list->mod);
		if (fd != -1)
			redirect_fd(fd);
		io_list = io_list->next_mod;
	}
}
