/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:32:00 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 19:35:10 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_char_index	*create_node(char *variable, char *equal, char *value)
{
	t_char_index	*node;

	node = malloc(sizeof(t_char_index));
	if (!node)
		return (NULL);
	if (variable)
		node->variable = strdup(variable);
	else
		node->variable = NULL;
	if (equal)
		node->equal = strdup(equal);
	else
		node->equal = NULL;
	if (value)
		node->value = strdup(value);
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
}

t_char_index	*find_last_node(t_char_index *head)
{
	t_char_index	*temp;

	temp = head;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

void	add_at_end(t_char_index **head, char *variable, char *equal,
		char *value)
{
	t_char_index	*node;
	t_char_index	*last;

	node = create_node(variable, equal, value);
	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = find_last_node(*head);
	last->next = node;
}

void	free_custom_split(char **split_result)
{
	if (split_result)
	{
		free(split_result[0]);
		free(split_result[1]);
		free(split_result);
	}
}

char	**custom_split(const char *str)
{
	char	**result;
	char	*equal_sign;
	int		left_len;

	result = malloc(3 * sizeof(char *));
	if (!result)
		return (NULL);
	equal_sign = strchr(str, '=');
	if (equal_sign)
	{
		left_len = equal_sign - str;
		result[0] = strndup(str, left_len);
		result[1] = strdup(equal_sign + 1);
	}
	else
	{
		result[0] = strdup(str);
		result[1] = NULL;
	}
	result[2] = NULL;
	return (result);
}
