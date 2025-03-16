/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_list_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:16 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 19:41:21 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	count_valid_nodes(t_char_index *head)
{
	int				count;
	t_char_index	*temp;

	count = 0;
	temp = head;
	while (temp)
	{
		if (temp->variable && temp->equal)
			count++;
		temp = temp->next;
	}
	return (count);
}

char	*join_node_components(t_char_index *node)
{
	char	*joined;
	size_t	total_len;

	if (node->value)
		total_len = strlen(node->variable) + strlen(node->equal)
			+ strlen(node->value) + 1;
	else
		total_len = strlen(node->variable) + strlen(node->equal) + 1;
	joined = malloc(total_len);
	if (!joined)
		return (NULL);
	strcpy(joined, node->variable);
	strcat(joined, node->equal);
	if (node->value)
		strcat(joined, node->value);
	return (joined);
}

char	**linked_list_to_2d_array(t_char_index *head)
{
	char			**env_array;
	t_char_index	*temp;
	int				i;

	env_array = malloc((count_valid_nodes(head) + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	temp = head;
	i = 0;
	while (temp)
	{
		if (temp->variable && temp->equal)
		{
			env_array[i] = join_node_components(temp);
			if (!env_array[i])
				return (NULL);
			i++;
		}
		temp = temp->next;
	}
	env_array[i] = NULL;
	return (env_array);
}
