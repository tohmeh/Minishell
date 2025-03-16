/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_char_array_functions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:40:48 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/13 18:57:36 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_dup_2d_array(char **arr)
{
	int		i;
	char	**new_arr;

	i = 0;
	while (arr[i] != NULL)
		i++;
	new_arr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

void	print_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

void	add_new_row(char ***arr, int new_rows)
{
	char	**temp_arr;
	int		i;

	i = -1;
	temp_arr = (char **)malloc(sizeof(char *) * (new_rows + 1));
	if (!temp_arr)
		return ;
	while (++i < new_rows - 1)
	{
		temp_arr[i] = ft_strdup((*arr)[i]);
		if (!temp_arr[i])
		{
			free_old_arr(temp_arr);
			return ;
		}
		free((*arr)[i]);
	}
	temp_arr[new_rows] = NULL;
	free(*arr);
	*arr = temp_arr;
}
