/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:35:55 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:47 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_pipe_tokens(char *str, int *k, t_token **current_token)
{
	(void)str;
	(*current_token)->next_token = init_token_type_and_value(PIPE, "|");
	(*k)++;
}
