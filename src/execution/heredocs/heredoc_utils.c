/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:00 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*generate_file(char *delimeter)
{
	char	*location;
	char	*temp_file;
	char	*counter_str;
	int		counter;

	counter = 1;
	location = ft_strjoin("/tmp/", delimeter);
	temp_file = ft_strjoin(location, "0");
	while (access(temp_file, F_OK) == 0)
	{
		free(temp_file);
		counter_str = ft_itoa(counter++);
		temp_file = ft_strjoin(location, counter_str);
		free(counter_str);
	}
	free(location);
	return (temp_file);
}

char	*write_heredoc_content(int temp_fd, const char *delimeter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, delimeter) == 0)
		{
			free(line);
			break ;
		}
		write(temp_fd, line, ft_strlen(line));
		write(temp_fd, "\n", 1);
		free(line);
	}
	return (NULL);
}

char	*read_here_doc(const char *delimeter)
{
	char	*temp_file;
	int		temp_fd;

	temp_file = generate_file("tmp");
	temp_fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (temp_fd == -1)
	{
		perror("Failed to open file");
		free(temp_file);
		g_signal_number = EXIT_FAILURE;
		exit(g_signal_number);
	}
	write_heredoc_content(temp_fd, delimeter);
	close(temp_fd);
	return (temp_file);
}

int	setup_stdin_backup(void)
{
	int	stdin_backup;

	stdin_backup = dup(STDIN_FILENO);
	if (stdin_backup == -1)
		perror("Failed to backup stdin");
	return (stdin_backup);
}

void	process_heredoc(t_io_modifier_list *current, int stdin_backup)
{
	char	*temp_file;

	if (dup2(stdin_backup, STDIN_FILENO) == -1)
	{
		perror("Failed to restore stdin");
		return ;
	}
	temp_file = read_here_doc(current->mod->file);
	if (temp_file)
	{
		free(current->mod->file);
		current->mod->file = temp_file;
		current->mod->type = REDIR_INPUT;
	}
}
