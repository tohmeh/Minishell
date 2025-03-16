/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:30:27 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 18:43:43 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	export_add(t_char_index **head, char *variable, char *equal,
		char *value)
{
	t_char_index	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (strcmp(temp->variable, variable) == 0)
		{
			free(temp->equal);
			if (equal)
				temp->equal = strdup(equal);
			else
				temp->equal = NULL;
			if (value)
			{
				free(temp->value);
				temp->value = strdup(value);
			}
			return ;
		}
		temp = temp->next;
	}
	add_at_end(head, variable, equal, value);
}
