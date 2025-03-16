/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:13:40 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:55:44 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_char_index	*init_environment(char **envp)
{
	char			**copy_env;
	t_char_index	*env_list;

	copy_env = ft_dup_2d_array(envp);
	env_list = env_to_linked_list(copy_env);
	free_2d_array(copy_env);
	return (env_list);
}

t_parsing_utils	*init_context(char **envp, char *input)
{
	t_parsing_utils	*ctx;

	ctx = (t_parsing_utils *)malloc(sizeof(t_parsing_utils));
	ctx->head_token = tokenize(input, envp);
	if (!ctx->head_token)
	{
		free(ctx);
		return (NULL);
	}
	ctx->current_cmd = NULL;
	return (ctx);
}

t_program_state	*init_program(int argc, char **argv, char **envp)
{
	t_program_state	*state;

	state = malloc(sizeof(t_program_state));
	if (!state)
		return (NULL);
	state->dir_state = init_dir_state(envp);
	state->copy_env = ft_dup_2d_array(envp);
	state->head = init_environment(envp);
	(void)argc;
	(void)argv;
	setup_signals();
	return (state);
}
