/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_semicolons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:36:24 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_semicolon_tokens(char *str, int *k, t_token **current_token)
{
	if (str[(*k) + 1] == ';')
	{
		(*current_token)->next_token = init_token_type_and_value(TERMINATOR,
				";;");
		(*k) += 2;
	}
	else
	{
		(*current_token)->next_token = init_token_type_and_value(SEMICOLON,
				";");
		(*k)++;
	}
}
