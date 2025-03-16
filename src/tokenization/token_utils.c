/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:15:43 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:27:13 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*init_token_type_and_value(t_token_type type, const char *value)
{
	t_token	*token_node;

	token_node = (t_token *)malloc(sizeof(t_token));
	token_node->next_token = NULL;
	token_node->type = type;
	token_node->value = ft_strdup(value);
	return (token_node);
}

void	skip_white_space(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

void	init_initial_quote_state(t_token_state *state, int *end, char *str)
{
	state->quote_state = 0;
	state->start = *end;
	state->end = end;
	state->str = str;
	state->quote_state = UNQUOTED;
}

t_token	*final_tokens_result(t_token *head_token)
{
	t_token	*current_token;

	current_token = head_token;
	head_token = head_token->next_token;
	free(current_token);
	return (head_token);
}
