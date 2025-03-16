/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:49:45 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:26:58 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	is_special_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '|' || c == '>'
		|| c == '<');
}

int	is_escapable_char(char c)
{
	return (c == '$' || c == '\"' || c == '\n');
}

int	is_command(char *token, char **env)
{
	char	*path;

	path = spec_com_path(env, token);
	if (path || is_builtin(token) || is_exec_path(token))
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

int	is_exec_path(char *token)
{
	if (token[0] == '/')
		return (1);
	if (token[0] == '.')
		if ((token[1] == '/' || (token[1] == '.' && token[2] == '/')))
			return (1);
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0);
}
