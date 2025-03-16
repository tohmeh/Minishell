/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:09 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:56:42 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_HANDLING_H

# define QUOTES_HANDLING_H

typedef struct quotes_variables
{
	int	i;
	int	j;
}		t_quotes_variable;

int		calculate_length_of_variable(char *str, char **env);
int		calculate_length(char *str, char **env);
int		count_in_double_quotes(char *str, char **env, int *i);
int		count_in_single_quotes(char *str, int *i);
int		count_env_variable(char *str, char **env, int *i);
void	change_quotes_state(char c, int *in_double_quotes,
			int *in_single_quotes, int *i);
void	replace_backslash(char *str, char *result, int *i, int *j);
void	process_char(char *str, char *result, int *i, int *j);
void	init_values(int *i, int *j, int *in_double_quotes,
			int *in_single_quotes);
char	*remove_quotes(char *str, char **env);
int		should_skip_expansion(char *str, int *i, char *result, int *j);
char	*extract_variable_name(char *str, int *i, int start);
void	copy_env_value(char *result, int *j, char *env_value);
void	expand_variables(char *str, char *result, t_quotes_variable *var,
			char **env);

#endif