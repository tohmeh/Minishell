/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:14:34 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:27:21 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*tokenize(char *str, char **env)
{
	t_token	*head_token;
	t_token	*current_token;
	int		k;

	k = 0;
	head_token = init_token_type_and_value(NOTOKEN, NULL);
	current_token = head_token;
	while (str[k] != '\0')
	{
		skip_white_space(str, &k);
		if (str[k] == '\0')
			break ;
		if (!tokenize_current_index(str, &k, &current_token, env))
		{
			free(head_token);
			free(str);
			return (NULL);
		}
		if (current_token->next_token)
			current_token = current_token->next_token;
	}
	free(str);
	return (final_tokens_result(head_token));
}
