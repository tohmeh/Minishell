/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:51:22 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:26:34 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	check_quotes_end(t_token_state *state)
{
	if (state->quote_state == DOUBLE_QUOTED)
	{
		if (state->str[*(state->end)] == '\"')
		{
			state->quote_state = UNQUOTED;
			(*(state->end))++;
		}
		else
			(*(state->end))++;
	}
	else if (state->quote_state == SINGLE_QUOTED)
	{
		if (state->str[*(state->end)] == '\'')
		{
			state->quote_state = UNQUOTED;
			(*(state->end))++;
		}
		else
			(*(state->end))++;
	}
}

void	change_quote_state(t_token_state *state)
{
	if (state->str[*(state->end)] == '\'')
		state->quote_state = SINGLE_QUOTED;
	else
		state->quote_state = DOUBLE_QUOTED;
	(*(state->end))++;
}

int	tokenize_final_line(t_token_state *state, t_token **current_token,
		char **env)
{
	char	*sub_str;

	if (state->quote_state != UNQUOTED)
	{
		printf("Quoting Error\n");
		return (0);
	}
	sub_str = malloc(sizeof(char) * (*(state->end) - state->start + 1));
	if (sub_str)
		ft_strlcpy(sub_str, &state->str[state->start], *(state->end)
			- state->start + 1);
	assign_token_to_line(sub_str, current_token, env);
	return (1);
}

int	tokenize_line(int *end, char *str,
		t_token **current_token, char **env)
{
	t_token_state	state;

	init_initial_quote_state(&state, end, str);
	while (str[*end] != '\0')
	{
		if (state.quote_state == UNQUOTED)
		{
			if (str[*end] == '\'' || str[*end] == '\"')
				change_quote_state(&state);
			else if (is_special_char(str[*end]))
				break ;
			else
				(*end)++;
		}
		else if (state.quote_state == SINGLE_QUOTED)
			check_quotes_end(&state);
		else if (state.quote_state == DOUBLE_QUOTED)
			check_quotes_end(&state);
	}
	if (!tokenize_final_line(&state, current_token, env))
		return (0);
	return (1);
}
