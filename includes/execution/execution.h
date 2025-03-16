/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:04 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/20 20:47:43 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../parsing/parsing.h"
# include "../predefined_lib.h"

typedef struct s_execute_ctx
{
	int					stdinput;
	int					stdoutput;
	int					num_pipes;
	int					**pipefd;
	pid_t				*pid;
	t_pipe_list			*head_pipe;
	t_io_modifier_list	*head_io;
	char				***envp;
	t_char_index		**env_head;
	t_dir_state			*dir_state;
	int					status;
}						t_execute_ctx;

void					pre_exec(t_command_line *command_line, char ***envp,
							t_char_index **head, t_dir_state *directory_state);
void					pre_exec_part2(t_command_line *command_line,
							t_execute_ctx *ctx, char ***envp);

/* Static function prototypes */
void					handle_single_builtin(t_command_line *command_line,
							char ***envp, t_char_index **head,
							t_dir_state *directory_state);
int						init_single_pipe(int **pipefd, int index);
int						init_pipes(t_execute_ctx *ctx);
void					close_pipes_in_child(t_execute_ctx *ctx,
							int current_pipe);
void					handle_child_process(t_command_line *command_line,
							t_execute_ctx *ctx, char ***envp, int pipe_index);
void					wait_for_children(t_execute_ctx *ctx);
void					close_current_pipes(t_execute_ctx *ctx, int i);
void					execute_pipeline(t_command_line *command_line,
							t_execute_ctx *ctx, char ***envp);
void					init_execution(t_command_line *command_line,
							t_execute_ctx *ctx);
int						allocate_pid_array(t_execute_ctx *ctx);
char					*spec_com_path(char **env, char *command);
int						get_num_pipes(t_command_line *command_node);
void					handle_empty_redirection(t_io_modifier_list *io_list);
void					execute_command(t_cmd_and_args **command, char ***envp);
void					redirect_output(t_io_modifier_list *io_list);
char					*generate_file(char *delimiter);
char					*read_here_doc(const char *delimiter);
void					redirect_input(t_io_modifier_list *io_list);
void					execute_builtin(t_cmd_and_args **cmd, char ***envp,
							t_char_index **head, t_dir_state *directory_state);
void					handle_heredocs(t_io_modifier_list *io_list);
void					handle_redirections(t_io_modifier_list *io_list, int i,
							int num_pipes, int **pipefd);
void					handle_empty_command(t_cmd_and_args *command);
char					*get_command_path(t_cmd_and_args *command, char **envp);
void					check_execution_permissions(char *path_command,
							char *command);
void					check_if_directory(char *path_command);
void					execute_with_path(char *path_command,
							t_cmd_and_args *command, char **envp);
char					*generate_file(char *delimeter);
char					*write_heredoc_content(int temp_fd,
							const char *delimeter);
int						setup_stdin_backup(void);
void					process_heredoc(t_io_modifier_list *current,
							int stdin_backup);
t_execute_ctx			*init_execute_ctx(char ***envp, t_char_index **head,
							t_dir_state *dir_state);
void					cleanup_execute_ctx(t_execute_ctx *ctx);

#endif