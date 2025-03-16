/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:02 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 19:45:46 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_char_index	**list_to_array(t_char_index *head, int count)
{
	t_char_index	**arr;
	t_char_index	*temp;
	int				i;

	arr = malloc(count * sizeof(t_char_index *));
	if (!arr)
		return (NULL);
	temp = head;
	i = 0;
	while (i < count)
	{
		arr[i] = temp;
		temp = temp->next;
		i++;
	}
	return (arr);
}

void	sort_array(t_char_index **arr, int count)
{
	int				i;
	int				j;
	t_char_index	*swap_temp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (strcmp(arr[j]->variable, arr[j + 1]->variable) > 0)
			{
				swap_temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap_temp;
			}
			j++;
		}
		i++;
	}
}

void	print_export_node(t_char_index *node)
{
	printf("declare -x %s", node->variable);
	if (node->equal)
	{
		printf("%s", node->equal);
		if (node->value)
			printf("\"%s\"", node->value);
		else
			printf("\"\"");
	}
	printf("\n");
}

void	print_sorted_nodes(t_char_index **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		print_export_node(arr[i]);
		i++;
	}
}

void	export_print(t_char_index *head)
{
	int				count;
	t_char_index	**arr;
	t_char_index	*temp;

	count = 0;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	arr = list_to_array(head, count);
	if (!arr)
		return ;
	sort_array(arr, count);
	print_sorted_nodes(arr, count);
	free(arr);
}
