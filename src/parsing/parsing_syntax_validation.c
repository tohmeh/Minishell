/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:36:16 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:24:08 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_redirect_token(t_token_type type)
{
	return (type == GREAT || type == GREATGREAT || type == LESS
		|| type == HEREDOC);
}

const char	*get_token_symbol(t_token_type type)
{
	if (type == PIPE)
		return ("|");
	else if (type == GREAT)
		return (">");
	else if (type == GREATGREAT)
		return (">>");
	else if (type == LESS)
		return ("<");
	else if (type == HEREDOC)
		return ("<<");
	else
		return ("newline");
}

int	validate_pipe_syntax(t_token *token)
{
	if (!token->next_token || token->next_token->type == PIPE)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	validate_redirect_syntax(t_token *token)
{
	if (!token->next_token)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (token->next_token->type != WORD && token->next_token->type != COMMAND
		&& token->next_token->type != OPTION)
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			get_token_symbol(token->next_token->type));
		return (0);
	}
	if (token->type == HEREDOC && (is_redirect_token(token->next_token->type)
			|| token->next_token->type == PIPE))
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			get_token_symbol(token->next_token->type));
		return (0);
	}
	return (1);
}

int	validate_syntax(t_token *token)
{
	t_token	*current;

	current = token;
	if (!current)
		return (1);
	if (current->type == PIPE)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	while (current)
	{
		if (current->type == PIPE && !validate_pipe_syntax(current))
			return (0);
		if (is_redirect_token(current->type)
			&& !validate_redirect_syntax(current))
			return (0);
		current = current->next_token;
	}
	return (1);
}
