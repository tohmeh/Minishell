/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:19:36 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:12:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H

# define PARSING_UTILS_H
# include "../tokenization/tokenization.h"

typedef struct s_arg_list
{
	char						**args;
	int							arg_count;
}								t_arg_list;

typedef struct s_cmd_and_args
{
	char						*command;
	t_arg_list					*args;
}								t_cmd_and_args;

typedef struct s_pipe_list
{
	t_cmd_and_args				*cmd;
	struct s_pipe_list			*next_pipe;
}								t_pipe_list;

typedef enum e_redirect_type
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	UNKNOWN
}								t_redirect_type;

typedef struct s_io_modifier
{
	t_redirect_type				type;
	char						*file;
}								t_io_modifier;

typedef struct s_io_modifier_list
{
	t_io_modifier				*mod;
	struct s_io_modifier_list	*next_mod;
}								t_io_modifier_list;

typedef struct s_command_line
{
	t_pipe_list					*pipe_list;
	t_io_modifier_list			*io_modifiers;
}								t_command_line;

typedef struct s_parsing_utils
{
	t_cmd_and_args				*current_cmd;
	t_token						*head_token;
}								t_parsing_utils;

t_command_line					*new_command_line(void);
t_pipe_list						*new_pipe_list(t_cmd_and_args *cmd);

/* Main parsing functions */
t_command_line					*parse_tokens(t_parsing_utils **ctx);
void							parse_command(t_parsing_utils **ctx,
									t_command_line *cmd_line,
									t_token *current_token);
void							parse_word(t_parsing_utils **ctx,
									t_command_line *cmd_line,
									t_token *current_token);
void							parse_pipe(t_parsing_utils **ctx,
									t_command_line *cmd_line);
void							parse_io_modifier(t_parsing_utils **ctx,
									t_command_line *cmd_line,
									t_token **current_token);
int								is_special_char(char c);
int								is_escapable_char(char c);
int								is_command(char *token, char **env);
int								is_exec_path(char *token);
int								is_builtin(char *cmd);

/* Helper functions */
t_redirect_type					get_redirect_type(char *value);
int								is_unexpected(t_token_type type);
void							free_tokens(t_token *head_token);
void							add_modifier_to_list(t_command_line *cmd_line,
									t_io_modifier *io_mod);
t_io_modifier					*create_io_modifier(t_token *token);
int								is_io_modifier_valid(t_token *token);
int								validate_syntax(t_token *token);
int								is_redirect_token(t_token_type type);
#endif