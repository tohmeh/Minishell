/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:13:52 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/03/15 01:56:22 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_args_count(char **args, int last_status)
{
	if (!args[1])
		exit(last_status);
	if (args[1] && args[2])
	{
		fprintf(stderr, "exit: too many arguments\n");
		g_signal_number = 1;
		return (1);
	}
	return (0);
}

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static void	check_overflow(const char *str, int i, int sign)
{
	unsigned long	max_test;

	max_test = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			fprintf(stderr, "exit: numeric argument required\n");
			g_signal_number = 255;
			exit(g_signal_number);
		}
		max_test = max_test * 10 + (str[i] - '0');
		if ((sign == 1 && max_test > 2147483647) || (sign == -1
				&& max_test > 2147483648))
		{
			fprintf(stderr, "exit: numeric argument required\n");
			g_signal_number = 255;
			exit(g_signal_number);
		}
		i++;
	}
}

void	exit_shell(char **args, int last_status)
{
	int		i;
	int		sign;
	long	num;

	if (check_args_count(args, last_status))
		return ;
	i = 0;
	sign = handle_sign(args[1], &i);
	check_overflow(args[1], i, sign);
	num = ft_atoi(args[1]);
	g_signal_number = (unsigned char)num;
	exit(g_signal_number);
}
