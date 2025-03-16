/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_length_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:50:54 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:24:25 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_in_double_quotes(char *str, char **env, int *i)
{
	int	length;

	length = 0;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != '\"')
	{
		if (str[*i] == '$')
		{
			(*i)++;
			if (str[*i] == '?')
				return (3);
			length += calculate_length_of_variable(&str[*i], env);
			while (str[*i] != '\0' && str[*i] != '$' && ft_isalpha(str[*i]))
				(*i)++;
		}
		else
		{
			length++;
			(*i)++;
		}
	}
	if (str[*i] == '\"')
		(*i)++;
	return (length);
}

int	count_in_single_quotes(char *str, int *i)
{
	int	length;

	length = 0;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != '\'')
	{
		length++;
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (length);
}

int	count_env_variable(char *str, char **env, int *i)
{
	int	length;

	(*i)++;
	if (str[*i] == '?')
		return (3);
	length = calculate_length_of_variable(&str[*i], env);
	while (str[*i] != '\0' && str[*i] != '$' && ft_isalpha(str[*i]))
		(*i)++;
	return (length);
}
