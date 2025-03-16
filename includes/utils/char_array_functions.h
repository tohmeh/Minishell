/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:01 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/13 17:16:33 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_ARRAY_FUNCTIONS_H
# define CHAR_ARRAY_FUNCTIONS_H

int		count_2d_char_array_rows(char **arr);
void	copy_2d_char_array(char **dest, char **src);
void	free_old_arr(char **arr);
void	copy_existing_rows(char **arr, char **new_arr, int *i);
void	real_2d_ch_arr(char ***arr, int new_rows, int new_cols);
void	add_new_row(char ***arr, int new_rows);
char	**dup_2d_char_array(char **arr);
void	print_2d_array(char **array);
char	**ft_dup_2d_array(char **arr);
void	ft_realloc_str(char **str, int newsize);

#endif