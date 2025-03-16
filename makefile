# Variables
NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Wunused-function
LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/lib/libft.a

# Source directories
SRC_DIR = src
BUILD_IN_DIR = $(SRC_DIR)/build_in
EXECUTION_DIR = $(SRC_DIR)/execution
TOKENIZATION_DIR = $(SRC_DIR)/tokenization
CHAR_ARRAY_FUNCTIONS_DIR = $(SRC_DIR)/utils/char_array_functions
ENV_FUNCTIONS_DIR = $(SRC_DIR)/utils/environment_functions
QUOTES_HANDLING_DIR = $(SRC_DIR)/quotes_handling
MAIN_DIR = $(SRC_DIR)/main
PARSING_DIR = $(SRC_DIR)/parsing

# Source files
SRCS =	$(BUILD_IN_DIR)/cd/cd.c \
		$(BUILD_IN_DIR)/cd/cd_pwd_oldpwd.c \
		$(BUILD_IN_DIR)/cd/init_cd.c \
		$(BUILD_IN_DIR)/cd/path_functions.c \
		$(BUILD_IN_DIR)/echo.c \
		$(BUILD_IN_DIR)/env.c \
		$(BUILD_IN_DIR)/exit.c \
		$(BUILD_IN_DIR)/pwd.c \
		$(BUILD_IN_DIR)/unset.c \
		$(BUILD_IN_DIR)/export/export_add_utils.c \
		$(BUILD_IN_DIR)/export/export_add.c \
		$(BUILD_IN_DIR)/export/export_error_check.c \
		$(BUILD_IN_DIR)/export/export_list_env.c \
		$(BUILD_IN_DIR)/export/export_print.c \
		$(BUILD_IN_DIR)/export/export.c \
		$(BUILD_IN_DIR)/export/export_env_list.c \
		$(EXECUTION_DIR)/builtin_exec/builtin.c \
		$(EXECUTION_DIR)/exec/execute.c \
		$(EXECUTION_DIR)/exec/execute_utils.c \
		$(EXECUTION_DIR)/heredocs/heredoc.c\
		$(EXECUTION_DIR)/heredocs/heredoc_utils.c\
		$(EXECUTION_DIR)/redirection/input_redirection.c \
		$(EXECUTION_DIR)/redirection/output_redirection.c \
		$(EXECUTION_DIR)/redirection/redirection.c \
		$(EXECUTION_DIR)/prexec.c \
		$(EXECUTION_DIR)/prexec_utils.c \
		$(EXECUTION_DIR)/pipes/pipes.c \
		$(EXECUTION_DIR)/pipes/pipes2.c \
		$(TOKENIZATION_DIR)/token.c \
		$(TOKENIZATION_DIR)/token_utils.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_ampersands.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_greaters.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_less.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_paranthesis.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_pipes.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_semicolons.c \
		$(TOKENIZATION_DIR)/sub_sub_tokenizers/assign_token_to_ligne.c \
		$(TOKENIZATION_DIR)/sub_tokenizers/line_tokenizer.c \
		$(TOKENIZATION_DIR)/sub_tokenizers/special_expression_tokenizer.c \
		$(TOKENIZATION_DIR)/sub_tokenizers/tokenizers.c\
		$(TOKENIZATION_DIR)/utils/identifiers.c \
		$(PARSING_DIR)/parsing.c \
		$(PARSING_DIR)/parsing_utils.c \
		$(PARSING_DIR)/parsing_syntax_validation.c \
		$(PARSING_DIR)/sub_parsers/parse_command.c \
		$(PARSING_DIR)/sub_parsers/parse_io.c \
		$(PARSING_DIR)/sub_parsers/parse_pipe.c \
		$(PARSING_DIR)/sub_parsers/parse_word.c \
		$(PARSING_DIR)/sub_parsers/parse_io_utils.c \
		$(QUOTES_HANDLING_DIR)/quotes.c \
		$(QUOTES_HANDLING_DIR)/calculate_length.c \
		$(QUOTES_HANDLING_DIR)/calculate_length_utils.c \
		$(QUOTES_HANDLING_DIR)/variable_extender.c \
		$(CHAR_ARRAY_FUNCTIONS_DIR)/char_array_functions.c \
		$(CHAR_ARRAY_FUNCTIONS_DIR)/2d_char_array_functions.c \
		$(CHAR_ARRAY_FUNCTIONS_DIR)/2d_char_array_functions2.c \
		$(ENV_FUNCTIONS_DIR)/get_env.c \
    	$(ENV_FUNCTIONS_DIR)/edit_env.c \
    	$(ENV_FUNCTIONS_DIR)/spec_cmd_path.c \
		$(MAIN_DIR)/main.c \
        $(MAIN_DIR)/utils/initializer.c \
		$(MAIN_DIR)/utils/cleaner.c \
		$(MAIN_DIR)/utils/create_prompt.c \
		$(MAIN_DIR)/utils/signals.c \

# Object files with preserved directory structure
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I $(LIBFT_DIR)/include

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

# Create object directories and compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re