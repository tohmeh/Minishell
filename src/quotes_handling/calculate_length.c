/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:47:30 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/08 19:56:00 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	calculate_length_of_variable(char *str, char **env)
{
	int		length;
	int		i;
	char	*temp;
	char	*env_value;

	length = 0;
	i = 0;
	if (str[i] == '\0' || str[i] == ' ' || str[i] == '\"')
		return (1);
	if (ft_isdigit(str[i]) || str[i] == '@' || str[i] == '!' || str[i] == '*'
		|| str[i] == '$')
		return (0);
	while (str[i] != '\0' && str[i] != '$' && ft_isalpha(str[i]))
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (length);
	ft_strlcpy(temp, str, i + 1);
	env_value = get_env_var(env, temp);
	free(temp);
	if (env_value)
		length += ft_strlen(env_value);
	free(env_value);
	return (length);
}

int	calculate_length(char *str, char **env)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			length += count_in_double_quotes(str, env, &i);
		else if (str[i] == '\'')
			length += count_in_single_quotes(str, &i);
		else if (str[i] == '$')
			length += count_env_variable(str, env, &i);
		else
		{
			length++;
			i++;
		}
	}
	return (length);
}
