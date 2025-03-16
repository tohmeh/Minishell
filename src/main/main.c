/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:50:16 by gakhoury          #+#    #+#             */
/*   Updated: 2025/03/15 02:01:52 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_command_execution(char *input, char ***copy_env,
		t_char_index *head, t_dir_state *dir_state)
{
	t_parsing_utils	*ctx;
	t_command_line	*cmd_line;

	ctx = init_context(*copy_env, input);
	if (!ctx)
	{
		return ;
	}
	cmd_line = parse_tokens(&ctx);
	if (cmd_line)
		pre_exec(cmd_line, copy_env, &head, dir_state);
	free_context(ctx);
	if (cmd_line)
	{
		free_io_list(&cmd_line->io_modifiers);
		free_pipe_list(&cmd_line->pipe_list);
	}
	free(cmd_line);
}

int	main(int argc, char **argv, char **envp)
{
	t_program_state	*state;
	char			*input;

	state = init_program(argc, argv, envp);
	if (!state)
		return (1);
	while (1)
	{
		input = read_input(envp, state->dir_state);
		if (!input)
		{
			printf("exit\n");
			g_signal_number = EXIT_SUCCESS;
			exit(g_signal_number);
		}
		if (input[0] != '\0')
			add_history(input);
		handle_command_execution(input, &state->copy_env, state->head,
			state->dir_state);
	}
	free_2d_array(state->copy_env);
	free(state->dir_state->logical_pwd);
	free(state->dir_state);
	free(state);
	return (0);
}
