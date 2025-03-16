/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:42:45 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 15:46:17 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*spec_com_path(char **env, char *command)
{
	int		i;
	char	*str;
	t_paths	p;

	i = -1;
	str = find_in_2d_array(env, "PATH=");
	if (!str)
		return (NULL);
	p.paths = ft_split(str + 5, ':');
	free(str);
	while (p.paths[++i] != NULL)
	{
		p.full_path = ft_strjoin(p.paths[i], "/");
		p.temp = ft_strjoin(p.full_path, command);
		free(p.full_path);
		p.full_path = p.temp;
		if (access(p.full_path, X_OK) == 0)
		{
			free_2d_array(p.paths);
			return (p.full_path);
		}
		free(p.full_path);
	}
	free_2d_array(p.paths);
	return (NULL);
}
