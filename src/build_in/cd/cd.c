/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:16:07 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 18:34:23 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_valid_directory(t_cd_data *data, char *new_physical)
{
	free(data->state->logical_pwd);
	data->state->logical_pwd = ft_strdup(new_physical);
	data->state->is_valid_dir = TRUE;
	edit_env(data->env, "OLDPWD", data->old_logical_pwd);
	edit_env(data->env, "PWD", new_physical);
}

void	handle_invalid_directory(t_cd_data *data)
{
	char	*new_path;

	data->state->is_valid_dir = FALSE;
	if (ft_strcmp(data->args[1], "..") == 0)
	{
		new_path = ft_strjoin(data->state->logical_pwd, "/..");
		if (new_path)
		{
			free(data->state->logical_pwd);
			data->state->logical_pwd = new_path;
		}
	}
	edit_env(data->env, "OLDPWD", data->old_logical_pwd);
	edit_env(data->env, "PWD", data->state->logical_pwd);
	printf("cd: error retrieving current directory:");
	printf(" getcwd: cannot access parent directories:");
	printf(" No such file or directory\n");
}

void	update_directory_state(t_cd_data *data)
{
	char	new_physical[PATH_MAX];

	if (getcwd(new_physical, PATH_MAX) != NULL)
		handle_valid_directory(data, new_physical);
	else
		handle_invalid_directory(data);
}

void	execute_cd(t_cd_data *data)
{
	if (chdir(data->target_path) == -1)
	{
		perror("cd");
		free(data->old_logical_pwd);
		free(data->target_path);
		return ;
	}
	update_directory_state(data);
	free(data->old_logical_pwd);
	free(data->target_path);
}

void	cd(char **args, char ***env, t_dir_state *state)
{
	t_cd_data	data;

	data.args = args;
	data.env = env;
	data.state = state;
	if (!init_cd(&data))
		return ;
	execute_cd(&data);
}
