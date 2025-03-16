/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in2darray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:24:08 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/06 18:53:41 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

char	*find_in_2d_array(char **strr, char *to_find)
{
	int	i;

	i = 0;
	while (strr[i] != NULL)
	{
		if (ft_strnstr(strr[i], to_find, ft_strlen(to_find)))
			return (ft_strdup(strr[i]));
		i++;
	}
	return (NULL);
}
