/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:12:32 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	handle_empty_command(t_cmd_and_args *command)
{
	if (!command->command || command->args->args[0][0] == '\0')
	{
		printf("minishell: %s: command not found\n", command->args->args[0]);
		g_signal_number = 127;
		exit(g_signal_number);
	}
}

char	*get_command_path(t_cmd_and_args *command, char **envp)
{
	char	*path_command;

	if (is_exec_path(command->command))
		path_command = ft_strdup(command->command);
	else
		path_command = spec_com_path(envp, command->command);
	if (!path_command)
	{
		g_signal_number = 127;
		exit(g_signal_number);
	}
	return (path_command);
}

void	check_execution_permissions(char *path_command, char *command)
{
	if (access(path_command, X_OK) != 0)
	{
		if (is_exec_path(command))
			printf("%s: No such file or directory\n", command);
		else
			printf("%s: command not found\n", command);
		free(path_command);
		g_signal_number = 127;
		exit(g_signal_number);
	}
}

void	check_if_directory(char *path_command)
{
	struct stat	path_stat;

	if (stat(path_command, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		printf("minishell: %s: is a directory\n", path_command);
		free(path_command);
		g_signal_number = 126;
		exit(g_signal_number);
	}
}

void	execute_with_path(char *path_command, t_cmd_and_args *command,
		char **envp)
{
	if (execve(path_command, command->args->args, envp) == -1)
	{
		perror("execve");
		free(path_command);
		g_signal_number = EXIT_FAILURE;
		exit(g_signal_number);
	}
}
