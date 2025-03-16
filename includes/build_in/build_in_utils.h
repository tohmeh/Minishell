/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:15:59 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 16:39:41 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_UTILS_H

# define BUILD_IN_UTILS_H

typedef int				t_bool;

typedef struct s_dir_state
{
	char				*logical_pwd;
	t_bool				is_valid_dir;
}						t_dir_state;

typedef struct s_cd_data
{
	char				**args;
	char				***env;
	t_dir_state			*state;
	char				*target_path;
	char				*old_logical_pwd;
}						t_cd_data;

typedef struct s_char_index
{
	char				*variable;
	char				*equal;
	char				*value;
	struct s_char_index	*next;
}						t_char_index;

t_char_index			*env_to_linked_list(char **env);
void					add_at_end(t_char_index **head, char *variable,
							char *equal, char *value);
char					**linked_list_to_2d_array(t_char_index *head);
char					*join_node_strings(t_char_index *node);
int						count_valid_entries(t_char_index *head);
int						check_first_part(char *str);
t_dir_state				*init_dir_state(char **env);
t_dir_state				*init_dir_state(char **env);
char					*handle_home_directory(char **env);
char					*handle_previous_directory(char **env);
void					handle_dir_change_failure(t_cd_data *data);
void					update_directory_state(t_cd_data *data);
char					*get_target_path(char **args, char ***env);
char					*reconstruct_path(char **components);
char					*resolve_path(const char *base, const char *rel_path);
int						init_cd(t_cd_data *data);
void					execute_cd(t_cd_data *data);
void					cd(char **args, char ***env, t_dir_state *state);
void					export_print(t_char_index *head);
char					**custom_split(const char *str);
void					export_add(t_char_index **head, char *variable,
							char *equal, char *value);
void					add_at_end(t_char_index **head, char *variable,
							char *equal, char *value);
t_char_index			*env_to_linked_list(char **env);
char					**linked_list_to_2d_array(t_char_index *head);
void					free_t_char_index(t_char_index *head);
void					sorted_insert(t_char_index **sorted_head,
							t_char_index *new_node);
t_char_index			*insertion_sort(t_char_index *head);
int						check_first_part(char *str);
void					free_custom_split(char **split_result);

#endif