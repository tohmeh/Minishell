/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:06 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 21:02:40 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "../execution/execution.h"

typedef struct s_program_state
{
	t_dir_state		*dir_state;
	char			**copy_env;
	t_char_index	*head;
}					t_program_state;

char			*remove_quotes(char *str, char **env);
char			*remove_backslashes(char *token);
char			*spec_com_path(char **env, char *command);
int				is_exec_path(char *token);
int				is_builtin(char *token);
t_parsing_utils	*init_context(char **envp, char *input);
t_command_line	*new_command_line(void);
t_token			*init_token_type_and_value(t_token_type type,
					const char *value);
char			*create_prompt(char **env, t_dir_state *directory_state);

void			free_tokens_list(t_token *head);
void			free_io_list(t_io_modifier_list **io_list);
void			free_context(t_parsing_utils *ctx);
void			free_pipe_list(t_pipe_list **pipe_list);
char			*read_input(char **env, t_dir_state *directory_state);
t_char_index	*init_environment(char **envp);
void			reset_signals_for_child(void);
void			ignore_signals(void);
void			setup_signals(void);
t_program_state	*init_program(int argc, char **argv, char **envp);

#endif