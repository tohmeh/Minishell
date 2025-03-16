/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:42:11 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	is_unexpected(t_token_type type)
{
	if (type == NEWLINE || type == SEMICOLON || type == LOGICAL_AND
		|| type == LOGICAL_OR || type == PIPE || type == GREAT
		|| type == GREATGREAT || type == GREATAMPERSAND || type == LESS
		|| type == HEREDOC || type == L_PARENTHESIS || type == R_PARENTHESIS
		|| type == NEWLINE || type == SEMICOLON || type == NEWLINE
		|| type == SEMICOLON)
		return (1);
	return (0);
}

int	is_io_modifier_valid(t_token *token)
{
	if (!token->next_token)
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			token->value);
		return (0);
	}
	else if (is_unexpected(token->next_token->type) == 1)
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			token->next_token->value);
		return (0);
	}
	return (1);
}

t_io_modifier	*create_io_modifier(t_token *token)
{
	t_io_modifier	*io_mod;

	io_mod = (t_io_modifier *)malloc(sizeof(t_io_modifier));
	if (!io_mod)
	{
		perror("malloc");
		g_signal_number = EXIT_FAILURE;
		exit(g_signal_number);
	}
	io_mod->type = get_redirect_type(token->value);
	return (io_mod);
}

void	add_modifier_to_list(t_command_line *cmd_line, t_io_modifier *io_mod)
{
	t_io_modifier_list	*new_mod_list;
	t_io_modifier_list	*last_mod;

	new_mod_list = (t_io_modifier_list *)malloc(sizeof(t_io_modifier_list));
	new_mod_list->mod = io_mod;
	new_mod_list->next_mod = NULL;
	if (!cmd_line->io_modifiers)
		cmd_line->io_modifiers = new_mod_list;
	else
	{
		last_mod = cmd_line->io_modifiers;
		while (last_mod->next_mod)
			last_mod = last_mod->next_mod;
		last_mod->next_mod = new_mod_list;
	}
}

t_redirect_type	get_redirect_type(char *value)
{
	if (ft_strcmp(value, ">") == 0)
		return (REDIR_OUTPUT);
	else if (ft_strcmp(value, "<") == 0)
		return (REDIR_INPUT);
	else if (ft_strcmp(value, ">>") == 0)
		return (REDIR_APPEND);
	else if (ft_strcmp(value, "<<") == 0)
		return (REDIR_HEREDOC);
	return (UNKNOWN);
}
