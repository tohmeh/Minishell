/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ampersands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:37:56 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:34 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_ampersand_tokens(char *str, int *k, t_token **current_token)
{
	if (str[(*k) + 1] == '&')
	{
		(*current_token)->next_token = init_token_type_and_value(LOGICAL_AND,
				"&&");
		(*k) += 2;
	}
	else
	{
		(*current_token)->next_token = init_token_type_and_value(AMPERSAND,
				"&");
		(*k)++;
	}
}
