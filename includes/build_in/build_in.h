/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:15:59 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:55:51 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H

# define BUILD_IN_H

# include "build_in_utils.h"

void	export(char **args, t_char_index **head, char ***env_ptr);
void	cd(char **args, char ***env, t_dir_state *t_dir_state);
void	echo(char **arguments, char ***env);
void	env(char **env);
void	exit_shell(char **args, int last_status);
void	pwd(t_dir_state *state);
void	unset(char **args, t_char_index **head, char ***env_ptr);

#endif