CC = cc

#CFLAGS = -Wall -Werror -Wextra

READLINE = -lreadline -L ~/goinfre/.brew/opt/readline/lib -I \
         ~/goinfre/.brew/opt/readline/include

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
	../execution_folder/echo_utilis.c\
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
	../parsing_folder/get_utils1.c \
	../parsing_folder/main.c
	
OBJS = ${SRCS:.c=.o}

NAME_EX = minishell

REM = rm -f

%.o : %.c
	@${CC} -c  $< -o $@

all : $(NAME_EX)
$(NAME_EX) : $(OBJS)
	@${CC}  ${READLINE} ${OBJS} -o $(NAME_EX)
	@echo "minishel made"

clean :
	@${REM} ${OBJS}
	@echo "object files deleted"

fclean : clean
	@${REM} ${NAME_EX}
	@echo "all files deleted"

re : fclean all

.PHONY : all clean fclean re