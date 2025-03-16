/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd_oldpwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:56:44 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 18:33:47 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*get_target_path(char **args, char ***env)
{
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		return (handle_home_directory(*env));
	else if (ft_strcmp(args[1], "-") == 0)
		return (handle_previous_directory(*env));
	return (ft_strdup(args[1]));
}

char	*handle_home_directory(char **env)
{
	char	*home_var;
	char	*target_path;

	home_var = get_env_var(env, "HOME");
	if (!home_var || !*home_var)
	{
		printf("cd: HOME not set\n");
		free(home_var);
		return (NULL);
	}
	target_path = ft_strdup(home_var);
	free(home_var);
	return (target_path);
}

char	*handle_previous_directory(char **env)
{
	char	*oldpwd;
	char	*target_path;

	oldpwd = get_env_var(env, "OLDPWD");
	if (!oldpwd || !*oldpwd)
	{
		write(2, "cd: OLDPWD not set\n", 19);
		free(oldpwd);
		return (NULL);
	}
	target_path = ft_strdup(oldpwd);
	if (target_path)
		ft_printf("%s\n", target_path);
	free(oldpwd);
	return (target_path);
}
