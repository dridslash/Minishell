CC = cc

CFLAGS = -Wall -Werror -Wextra

READLINE = -lreadline -L ~/goinfre/.brew/opt/readline/lib -I ~/goinfre/.brew/opt/readline/include

SRCS = ../execution_folder/ft_split_execution.c \
	../execution_folder/ft_strdup.c \
	../execution_folder/get_next_line_execution.c \
	../execution_folder/ft_strtrim.c \
	../execution_folder/gl_line_execution_ul.c\
	../execution_folder/exectuion_her_doc_utils00.c\
	../execution_folder/execution_utils02.c\
	../execution_folder/execution_utils00.c\
	../execution_folder/execution_utils01.c\
	../execution_folder/ff_check_errors_export_01.c\
	../execution_folder/ff_check_errors_export.c\
	../execution_folder/ff_export_utils.c\
	../execution_folder/ft_pwd.c\
	../execution_folder/separ_main_three.c\
	../execution_folder/separ_help_of_help_two.c\
	../execution_folder/separ_send_redi_three.c\
	../execution_folder/separat_send_redi.c\
	../execution_folder/handle_dollar_export_ut00.c\
	../execution_folder/ft_error_manage_ut00.c\
	../execution_folder/hlp_main_three_ut01.c\
	../execution_folder/hlp_main_two_utils_01.c\
	../execution_folder/execute_her_doccc.c\
	../execution_folder/execution_help_of_help_two01_ut.c\
	../execution_folder/execution_help_of_help_ut01.c\
	../execution_folder/execute_commands_glb_ut01.c\
	../execution_folder/echo_utilis.c\
	../execution_folder/hlp_main_three_ut00.c\
	../execution_folder/hlp_main_two_utils00.c\
	../execution_folder/ft_itoa.c\
	../execution_folder/execution_help_of_help_ut00.c\
	../execution_folder/execution_help_of_help_two_ut00.c\
	../execution_folder/execution_commands_global_utils00.c\
	../execution_folder/execute_command_global_utl00.c\
	../execution_folder/built_in_utils.c\
	../execution_folder/handle_mark.c\
	../execution_folder/ft_error_manage.c\
	../execution_folder/ff_handle_dollar_export.c\
	../execution_folder/ff_part_two_of_export.c\
	../execution_folder/ff_part_one_of_export.c\
	../execution_folder/ft_exit.c\
	../execution_folder/ft_unset.c\
	../execution_folder/ft_env_show.c\
	../execution_folder/ft_export.c\
	../execution_folder/sort_alphabets.c\
	../execution_folder/ft_cd.c\
	../execution_folder/get_path.c \
	../execution_folder/count_argc.c \
	../execution_folder/get_params.c \
	../execution_folder/ft_strnstr.c \
	../execution_folder/execution.c \
	../execution_folder/ft_atoi.c \
	../execution_folder/ft_echo.c \
	../execution_folder/ft_isalpha.c \
	../execution_folder/ft_isascii.c \
	../execution_folder/ft_isdigit.c \
	../execution_folder/ft_strcmp.c \
	../execution_folder/ft_strjoin_non_free.c \
	../execution_folder/ft_strstr.c \
	../parsing_folder/error_functions2.c \
	../parsing_folder/error_functions.c \
	../parsing_folder/split_input1.c \
	../parsing_folder/split_input2.c \
	../parsing_folder/split_input3.c \
	../parsing_folder/split_input4.c \
	../parsing_folder/split_input5.c \
	../parsing_folder/split_input6.c \
	../parsing_folder/take_input.c \
	../parsing_folder/exec_test.c \
	../parsing_folder/dollar_handling1.c \
	../parsing_folder/dollar_handling2.c \
	../parsing_folder/dollar_handling3.c \
	../parsing_folder/split_function.c \
	../parsing_folder/dollar_handling4.c \
	../parsing_folder/parsing1.c \
	../parsing_folder/parsing2.c \
	../parsing_folder/parsing3.c \
	../parsing_folder/get_next_line.c \
	../parsing_folder/get_next_line_utils.c \
	../parsing_folder/main.c\
	../parsing_folder/history.c\
	../parsing_folder/leak_functions.c\
	../parsing_folder/get_02.c
	
OBJS = ${SRCS:.c=.o}

NAME = minishell

REM = rm -f

%.o : %.c
	@${CC} ${CFLAGS} -c  $< -o $@

all : $(NAME)
$(NAME) : $(OBJS)
	@${CC} ${CFLAGS} ${READLINE} ${OBJS} -o $(NAME)
	@echo "\033[33;3mMinishell made !\033[0m"

clean :
	@${REM} ${OBJS}
	@echo "\033[31;5mObject files deleted !\033[0m"

fclean : clean
	@${REM} ${NAME}
	@echo "\033[31;5mAll files deleted !\033[0m"

re : fclean all

.PHONY : all clean fclean re
