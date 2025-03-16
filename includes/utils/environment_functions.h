/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_functions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:12 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:56:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_FUNCTIONS_H

# define ENVIRONMENT_FUNCTIONS_H

typedef struct paths
{
	char	**paths;
	char	*full_path;
	char	*temp;
}			t_paths;

char		*get_env_var(char **env, char *var);
void		edit_env(char ***envp, const char *name, const char *value);
int			find_existing_variable(char **envp, const char *name, int name_len);
char		*create_new_entry(const char *name, const char *value);
void		add_new_variable(char ***envp, const char *name, const char *value);
#endif