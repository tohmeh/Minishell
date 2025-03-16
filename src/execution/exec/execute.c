/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:38 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 15:12:57 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	execute_command(t_cmd_and_args **command, char ***envp)
{
	char	*path_command;

	handle_empty_command(*command);
	path_command = get_command_path(*command, *envp);
	check_execution_permissions(path_command, (*command)->command);
	check_if_directory(path_command);
	execute_with_path(path_command, *command, *envp);
	free(path_command);
	exit(EXIT_FAILURE);
}
