/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:45:33 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 18:40:48 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	validate_args(char **args)
{
	if (!args[1])
	{
		printf("unset: not enough arguments\n");
		return (0);
	}
	return (1);
}

static void	remove_node(t_char_index **head, t_char_index *prev,
		t_char_index *current)
{
	if (prev)
		prev->next = current->next;
	else
		*head = current->next;
	free(current->variable);
	free(current->equal);
	free(current->value);
	free(current);
}

static void	process_argument(char *arg, t_char_index **head)
{
	t_char_index	*prev;
	t_char_index	*current;

	if (!check_first_part(arg))
	{
		printf("unset: `%s': not a valid identifier\n", arg);
		return ;
	}
	prev = NULL;
	current = *head;
	while (current)
	{
		if (strcmp(current->variable, arg) == 0)
		{
			remove_node(head, prev, current);
			break ;
		}
		prev = current;
		current = current->next;
	}
}

static void	update_env(char ***env_ptr, char **new_env)
{
	int	j;

	if (*env_ptr)
	{
		j = 0;
		while ((*env_ptr)[j])
		{
			free((*env_ptr)[j]);
			j++;
		}
		free(*env_ptr);
	}
	*env_ptr = new_env;
}

void	unset(char **args, t_char_index **head, char ***env_ptr)
{
	int		i;
	char	**new_env;

	if (!validate_args(args))
		return ;
	i = 1;
	while (args[i])
	{
		process_argument(args[i], head);
		i++;
	}
	new_env = linked_list_to_2d_array(*head);
	update_env(env_ptr, new_env);
}
