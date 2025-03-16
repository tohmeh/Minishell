/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:15:57 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:56:48 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_UTILS_H
# define TOKENIZATION_UTILS_H

# include "../execution/execution.h"

typedef enum e_token_type
{
	GREAT,
	LESS,
	INPUT_OUTPUT,
	HEREDOC,
	PIPE,
	GREATGREAT,
	GREATAMPERSAND,
	LOGICAL_AND,
	LOGICAL_OR,
	EVENT,
	SEMICOLON,
	TERMINATOR,
	AMPERSAND,
	L_PARENTHESIS,
	R_PARENTHESIS,
	WORD,
	COMMAND,
	OPTION,
	NOTOKEN,
	MY_NEWLINE,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next_token;
}					t_token;

typedef enum e_quote_state
{
	UNQUOTED,
	SINGLE_QUOTED,
	DOUBLE_QUOTED
}					t_quote_state;

typedef struct s_token_state
{
	int				start;
	int				*end;
	char			*str;
	int				quoting_error;
	t_quote_state	quote_state;
}					t_token_state;

void				assign_pipe_tokens(char *str, int *k,
						t_token **current_token);
void				assign_great_tokens(char *str, int *k,
						t_token **current_token);
void				assign_less_tokens(char *str, int *k,
						t_token **current_token);
void				assign_ampersand_tokens(char *str, int *k,
						t_token **current_token);
void				assign_semicolon_tokens(char *str, int *k,
						t_token **current_token);
void				assign_special_chars(char *str, int *k,
						t_token **current_token);
void				tokenize_special_expression(char *str, int *k,
						t_token **current_token);
void				assign_token_to_line(char *temp0, t_token **current_token,
						char **env);

void				skip_white_space(char *str, int *i);
char				*remove_quotes(char *str, char **env);

int					tokenize_line(int *end, char *str, t_token **current_token,
						char **env);
t_token				*init_token_type_and_value(t_token_type type,
						const char *value);

void				init_initial_quote_state(t_token_state *state, int *end,
						char *str);
int					is_special_char(char c);
int					is_escapable_char(char c);
int					is_command(char *token, char **env);

void				handle_backslash(t_token_state *state);
void				change_quote_state(t_token_state *state);
void				check_single_quote_end(t_token_state *state);
void				check_double_quote_end(t_token_state *state);
int					tokenize_final_line(t_token_state *state,
						t_token **current_token, char **env);
int					tokenize_current_index(char *str, int *k,
						t_token **current_token, char **env);
t_token				*final_tokens_result(t_token *head_token);

#endif