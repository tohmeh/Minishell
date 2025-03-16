/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:22:37 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/13 22:52:49 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_export_no_args(t_char_index *head)
{
	if (head)
		export_print(head);
}

int	find_variable(t_char_index *head, const char *variable)
{
	t_char_index	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->variable, variable) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	update_env_ptr(char ***env_ptr, t_char_index *head)
{
	char	**new_env;
	int		j;

	new_env = linked_list_to_2d_array(head);
	if (*env_ptr)
	{
		j = 0;
		while ((*env_ptr)[j] != NULL)
		{
			free((*env_ptr)[j]);
			j++;
		}
		free(*env_ptr);
	}
	*env_ptr = new_env;
}

void	process_export_arg(t_char_index **head, char *arg)
{
	char	**split;
	char	*equal_sign;

	split = custom_split(arg);
	if (!check_first_part(split[0]))
		printf("export: `%s': not a valid identifier\n", arg);
	else
	{
		equal_sign = ft_strchr(arg, '=');
		if (equal_sign)
			export_add(head, split[0], "=", split[1]);
		else if (!find_variable(*head, split[0]))
			add_at_end(head, split[0], NULL, NULL);
	}
	free_custom_split(split);
}

void	export(char **args, t_char_index **head, char ***env_ptr)
{
	int	i;

	if (!args[1])
	{
		handle_export_no_args(*head);
		return ;
	}
	i = 1;
	while (args[i] != NULL)
	{
		process_export_arg(head, args[i]);
		i++;
	}
	update_env_ptr(env_ptr, *head);
}
