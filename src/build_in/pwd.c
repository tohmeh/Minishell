/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:47:46 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd(t_dir_state *state)
{
	if (state->logical_pwd)
	{
		ft_printf("%s\n", state->logical_pwd);
		g_signal_number = 0;
	}
	else
	{
		ft_printf("pwd: error retrieving current directory\n");
		g_signal_number = 1;
	}
}
