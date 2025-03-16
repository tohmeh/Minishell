/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:06 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:56:21 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../execution/execution.h"
# include "main_utils.h"

void	handle_command_execution(char *input, char ***copy_env,
			t_char_index *head, t_dir_state *directory_state);

#endif