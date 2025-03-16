/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:39:34 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	handle_single_builtin(t_command_line *command_line, char ***envp,
		t_char_index **head, t_dir_state *directory_state)
{
	if (command_line->io_modifiers)
	{
		handle_heredocs(command_line->io_modifiers);
		redirect_input(command_line->io_modifiers);
		redirect_output(command_line->io_modifiers);
	}
	execute_builtin(&command_line->pipe_list->cmd, envp, head, directory_state);
}

void	execute_builtin(t_cmd_and_args **cmd, char ***envp, t_char_index **head,
		t_dir_state *directory_state)
{
	if (ft_strcmp((*cmd)->command, "echo") == 0)
		echo((*cmd)->args->args, envp);
	else if (ft_strcmp((*cmd)->command, "cd") == 0)
		cd((*cmd)->args->args, envp, directory_state);
	else if (ft_strcmp((*cmd)->command, "pwd") == 0)
		pwd(directory_state);
	else if (ft_strcmp((*cmd)->command, "export") == 0)
		export((*cmd)->args->args, head, envp);
	else if (ft_strcmp((*cmd)->command, "unset") == 0)
		unset((*cmd)->args->args, head, envp);
	else if (ft_strcmp((*cmd)->command, "env") == 0)
		env(*envp);
	else if (ft_strcmp((*cmd)->command, "exit") == 0)
		exit_shell((*cmd)->args->args, g_signal_number);
}
