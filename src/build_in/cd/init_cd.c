/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:21:53 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/13 20:16:23 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_dir_state	*init_dir_state(char **env)
{
	t_dir_state	*state;
	char		current[PATH_MAX];
	char		*pwd;

	state = malloc(sizeof(t_dir_state));
	if (!state)
		return (NULL);
	if (getcwd(current, PATH_MAX) != NULL)
	{
		state->logical_pwd = ft_strdup(current);
		state->is_valid_dir = TRUE;
	}
	else
	{
		pwd = get_env_var(env, "PWD");
		if (pwd)
			state->logical_pwd = ft_strdup(pwd);
		else
			state->logical_pwd = ft_strdup("/");
		state->is_valid_dir = FALSE;
	}
	return (state);
}

int	init_cd(t_cd_data *data)
{
	int	arg_count;

	arg_count = 0;
	while (data->args[arg_count])
		arg_count++;
	if (arg_count > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (0);
	}
	data->target_path = get_target_path(data->args, data->env);
	if (!data->target_path)
		return (0);
	data->old_logical_pwd = ft_strdup(data->state->logical_pwd);
	if (!data->old_logical_pwd)
	{
		free(data->target_path);
		return (0);
	}
	return (1);
}
