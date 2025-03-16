/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:00:22 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/05 19:37:59 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	edit_env(char ***envp, const char *name, const char *value)
{
	int		i;
	char	*new_entry;
	int		name_len;

	i = 0;
	name_len = ft_strlen(name);
	i = find_existing_variable(*envp, name, name_len);
	if (i != -1)
	{
		new_entry = create_new_entry(name, value);
		if (!new_entry)
			return ;
		free((*envp)[i]);
		(*envp)[i] = new_entry;
		return ;
	}
	add_new_variable(envp, name, value);
}

int	find_existing_variable(char **envp, const char *name, int name_len)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], name, name_len) && envp[i][name_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*create_new_entry(const char *name, const char *value)
{
	char	*new_entry;
	char	*temp;

	new_entry = ft_strjoin(name, "=");
	if (!new_entry)
		return (NULL);
	temp = new_entry;
	new_entry = ft_strjoin(new_entry, value);
	if (!new_entry)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (new_entry);
}

void	add_new_variable(char ***envp, const char *name, const char *value)
{
	int		i;
	char	*new_entry;

	i = count_2d_char_array_rows(*envp);
	real_2d_ch_arr(envp, i + 1, ft_strlen(name) + 1 + ft_strlen(value) + 1);
	new_entry = create_new_entry(name, value);
	if (!new_entry)
		return ;
	(*envp)[i] = new_entry;
	(*envp)[i + 1] = NULL;
}
