/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:10:22 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/13 20:02:40 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*reconstruct_path(char **components)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (components[i])
	{
		temp = result;
		result = ft_strjoin(result, "/");
		free(temp);
		temp = result;
		result = ft_strjoin(result, components[i]);
		free(temp);
		i++;
	}
	if (!*result)
	{
		free(result);
		result = ft_strdup("/");
	}
	return (result);
}

char	*resolve_path(const char *base, const char *rel_path)
{
	char	**components;
	char	*result;
	int		i;

	components = ft_split(base, '/');
	if (!components)
		return (NULL);
	if (ft_strcmp(rel_path, "..") == 0)
	{
		i = 0;
		while (components[i])
			i++;
		if (i > 0)
			free(components[--i]);
		components[i] = NULL;
	}
	result = reconstruct_path(components);
	i = 0;
	while (components[i])
		free(components[i++]);
	free(components);
	return (result);
}
