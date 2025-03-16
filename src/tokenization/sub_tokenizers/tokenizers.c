/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:57:17 by gakhoury          #+#    #+#             */
/*   Updated: 2025/03/14 01:26:48 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	tokenize_current_index(char *str, int *k, t_token **current_token,
		char **env)
{
	if (is_special_char(str[*k]))
		tokenize_special_expression(str, k, current_token);
	else
		if (!tokenize_line(k, str, current_token, env))
			return (0);
	return (1);
}
