/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_expression_tokenizer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:58:01 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/10 16:01:09 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	tokenize_special_expression(char *str, int *k, t_token **current_token)
{
	if (str[*k] == '|')
		assign_pipe_tokens(str, k, current_token);
	else if (str[(*k)] == '>')
		assign_great_tokens(str, k, current_token);
	else if (str[(*k)] == '<')
		assign_less_tokens(str, k, current_token);
	else if (str[(*k)] == '&')
		assign_ampersand_tokens(str, k, current_token);
	else if (str[(*k)] == ';')
		assign_semicolon_tokens(str, k, current_token);
	else
		assign_special_chars(str, k, current_token);
}
