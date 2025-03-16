/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_token_to_ligne.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:27:37 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:26:12 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	assign_token_to_line(char *str, t_token **current_token, char **env)
{
	char	*unquoted;

	unquoted = NULL;
	unquoted = remove_quotes(str, env);
	free(str);
	str = unquoted;
	if (str && str[0] == '-')
		(*current_token)->next_token = init_token_type_and_value(OPTION, str);
	else if (is_command(str, env))
		(*current_token)->next_token = init_token_type_and_value(COMMAND,
				str);
	else
		(*current_token)->next_token = init_token_type_and_value(WORD, str);
	free(str);
}
