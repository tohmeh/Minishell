/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:27:49 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:24:36 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_quotes_state(char c, int *in_double_quotes,
		int *in_single_quotes, int *i)
{
	if (c == '\"' && !(*in_single_quotes))
	{
		*in_double_quotes = !(*in_double_quotes);
	}
	else if (c == '\'' && !(*in_double_quotes))
	{
		*in_single_quotes = !(*in_single_quotes);
	}
	(*i)++;
}

void	process_char(char *str, char *result, int *i, int *j)
{
	result[(*j)++] = str[(*i)++];
}

void	init_values(int *i, int *j, int *in_double_quotes,
		int *in_single_quotes)
{
	*i = 0;
	*j = 0;
	*in_double_quotes = 0;
	*in_single_quotes = 0;
}

char	*remove_quotes(char *str, char **env)
{
	t_quotes_variable	var;
	char				*result;
	int					in_double_quotes;
	int					in_single_quotes;

	init_values(&var.i, &var.j, &in_double_quotes, &in_single_quotes);
	result = malloc(sizeof(char) * (calculate_length(str, env) + 1));
	if (!result)
		return (NULL);
	while (str[var.i] != '\0')
	{
		if ((str[var.i] == '\"' && in_single_quotes))
			process_char(str, result, &var.i, &var.j);
		else if (str[var.i] == '\'' && in_double_quotes)
			process_char(str, result, &var.i, &var.j);
		else if (str[var.i] == '\"' || str[var.i] == '\'')
			change_quotes_state(str[var.i], &in_double_quotes,
				&in_single_quotes, &var.i);
		else if (str[var.i] == '$' && !in_single_quotes)
			expand_variables(str, result, &var, env);
		else
			process_char(str, result, &var.i, &var.j);
	}
	result[var.j] = '\0';
	return (result);
}
