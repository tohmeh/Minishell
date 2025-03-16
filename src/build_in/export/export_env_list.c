/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:39:50 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 19:41:14 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_char_index	*create_env_node(const char *var, int var_len,
		const char *value)
{
	t_char_index	*new_node;

	new_node = malloc(sizeof(t_char_index));
	if (!new_node)
		return (NULL);
	new_node->variable = strndup(var, var_len);
	new_node->equal = strdup("=");
	new_node->value = strdup(value);
	new_node->next = NULL;
	return (new_node);
}

void	add_env_node(t_char_index **head, t_char_index **current,
		t_char_index *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		*current = *head;
	}
	else
	{
		(*current)->next = new_node;
		*current = new_node;
	}
}

t_char_index	*env_to_linked_list(char **env)
{
	t_char_index	*head;
	t_char_index	*current;
	char			*equal_sign;
	t_char_index	*new_node;

	head = NULL;
	current = NULL;
	while (*env)
	{
		equal_sign = strchr(*env, '=');
		if (equal_sign)
		{
			new_node = create_env_node(*env, equal_sign - *env, equal_sign + 1);
			if (!new_node)
				return (NULL);
			add_env_node(&head, &current, new_node);
		}
		env++;
	}
	return (head);
}
