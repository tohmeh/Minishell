/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_extender.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:52:09 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 19:25:20 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	should_skip_expansion(char *str, int *i, char *result, int *j)
{
	if (str[*i] == '\0' || str[*i] == ' ' || str[*i] == '\"' || str[*i] == '?')
	{
		result[(*j)++] = '$';
		return (1);
	}
	if (str[*i] == '@' || str[*i] == '!'
		|| str[*i] == '=' || str[*i] == ':'
		|| str[*i] == '*' || str[*i] == '$')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

char	*extract_variable_name(char *str, int *i, int start)
{
	char	*temp;

	while (str[*i] != '\0' && str[*i] != '$' && str[*i] != ' '
		&& str[*i] != '\"' && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	temp = malloc(sizeof(char) * ((*i) - start + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, &str[start], (*i) - start + 1);
	return (temp);
}

void	copy_env_value(char *result, int *j, char *env_value)
{
	int	k;

	if (!env_value)
		return ;
	k = 0;
	while (env_value[k])
		result[(*j)++] = env_value[k++];
}

void	expand_variables(char *str, char *result,
	t_quotes_variable *var, char **env)
{
	int		start;
	char	*temp;
	char	*env_value;

	(var->i)++;
	start = (var->i);
	if (should_skip_expansion(str, &var->i, result, &var->j))
		return ;
	temp = extract_variable_name(str, &var->i, start);
	if (!temp)
		return ;
	env_value = get_env_var(env, temp);
	copy_env_value(result, &var->j, env_value);
	if (env_value)
		free(env_value);
	free(temp);
}
