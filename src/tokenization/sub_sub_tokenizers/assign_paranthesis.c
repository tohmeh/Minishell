/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_paranthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:28:50 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:44 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_special_chars(char *str, int *k, t_token **current_token)
{
	if (str[(*k)] == '(')
	{
		(*current_token)->next_token = init_token_type_and_value(L_PARENTHESIS,
				"(");
		(*k)++;
	}
	else if (str[(*k)] == ')')
	{
		(*current_token)->next_token = init_token_type_and_value(R_PARENTHESIS,
				")");
		(*k)++;
	}
}
