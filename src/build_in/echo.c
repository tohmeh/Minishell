/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:01:07 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	echo_option_check(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' || str[1] != 'n')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_print(int i, char **arguments, char ***env)
{
	char	*home;

	if (ft_strncmp(arguments[(i)], "$?", 2) == 0)
	{
		printf("%d", g_signal_number);
		if (arguments[i][2])
			printf("%s", &arguments[i][2]);
	}
	else if (arguments[i][0] == '~' && (arguments[i][1] == '\0'
			|| arguments[i][1] == '/'))
	{
		home = get_env_var(*env, "HOME");
		if (home)
		{
			printf("%s", home);
			if (arguments[i][1] == '/')
				printf("%s", arguments[i] + 1);
		}
		else
			printf("~");
	}
	else
		printf("%s", arguments[i]);
	if (arguments[(i) + 1] != NULL)
		printf(" ");
}

void	echo(char **arguments, char ***env)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (arguments[i] && echo_option_check(arguments[i]))
	{
		newline = 0;
		i++;
	}
	while (arguments[i] != NULL)
	{
		echo_print(i, arguments, env);
		i++;
	}
	if (newline)
		printf("\n");
	g_signal_number = 0;
}
