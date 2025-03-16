/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_greaters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:11 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:38 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_great_tokens(char *str, int *k, t_token **current_token)
{
	(*k)++;
	if (str[(*k)] == '>')
	{
		(*k)++;
		(*current_token)->next_token = init_token_type_and_value(GREATGREAT,
				">>");
	}
	else if (str[(*k)] == '&')
	{
		(*k)++;
		(*current_token)->next_token = init_token_type_and_value(GREATAMPERSAND,
				">&");
	}
	else
		(*current_token)->next_token = init_token_type_and_value(GREAT, ">");
}
