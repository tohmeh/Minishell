/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:23 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 02:02:21 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	g_signal_number = 0;

char	*format_prompt(char *user, const char *path)
{
	char	*prompt;
	char	*temp;

	prompt = ft_strjoin("\001\033[1;32m\002", user);
	if (user)
		free(user);
	temp = ft_strjoin(prompt, "\001\033[0m\002:");
	free(prompt);
	prompt = ft_strjoin(temp, "\001\033[1;34m\002");
	free(temp);
	temp = ft_strjoin(prompt, path);
	free(prompt);
	prompt = ft_strjoin(temp, "\001\033[0m\002$ ");
	free(temp);
	return (prompt);
}

int	is_only_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

char	*read_input(char **env, t_dir_state *directory_state)
{
	char	*line;
	char	*input;
	char	**copy_env;

	copy_env = ft_dup_2d_array(env);
	line = create_prompt(copy_env, directory_state);
	while (1)
	{
		input = readline(line);
		if (input == NULL)
			break ;
		if (*input != '\0' && !is_only_whitespace(input))
			break ;
		free(input);
	}
	free(line);
	free_2d_array(copy_env);
	return (input);
}

char	*create_prompt(char **env, t_dir_state *state)
{
	char	*prompt;
	char	*user;

	user = get_env_var(env, "USER");
	if (!user)
		user = ft_strdup("user");
	prompt = format_prompt(user, state->logical_pwd);
	return (prompt);
}
