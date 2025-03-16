/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:33:05 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/09/17 18:48:32 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_realloc_str(char **str, int newsize)
{
	char	*new_str;

	new_str = (char *)malloc(newsize);
	if (!new_str)
		return ;
	ft_strlcpy(new_str, *str, newsize);
	free(*str);
	*str = new_str;
}
