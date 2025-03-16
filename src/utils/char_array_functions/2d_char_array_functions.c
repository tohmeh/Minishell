/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_char_array_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:31:24 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/05 16:25:57 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_2d_char_array_rows(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}

void	copy_2d_char_array(char **dest, char **src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != NULL)
	{
		j = 0;
		while (src[i][j] != '\0')
		{
			dest[i][j] = src[i][j];
			j++;
		}
		dest[i][j] = '\0';
		i++;
	}
}

void	free_old_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	copy_existing_rows(char **arr, char **new_arr, int *i)
{
	while (arr[*i] != NULL)
	{
		new_arr[*i] = (char *)malloc((strlen(arr[*i]) + 1) * sizeof(char));
		if (!new_arr[*i])
		{
			free_old_arr(new_arr);
			return ;
		}
		strcpy(new_arr[*i], arr[*i]);
		(*i)++;
	}
}

void	real_2d_ch_arr(char ***arr, int new_rows, int new_cols)
{
	char	**new_arr;
	int		i;

	i = 0;
	new_arr = (char **)malloc((new_rows + 1) * sizeof(char *));
	if (!new_arr)
		return ;
	copy_existing_rows(*arr, new_arr, &i);
	while (i < new_rows - 1)
	{
		new_arr[i] = (char *)malloc((new_cols + 1) * sizeof(char));
		if (!new_arr[i])
		{
			free_old_arr(new_arr);
			return ;
		}
		i++;
	}
	new_arr[i] = NULL;
	copy_2d_char_array(new_arr, *arr);
	free_old_arr(*arr);
	*arr = new_arr;
}
