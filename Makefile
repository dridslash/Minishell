CC = cc -c

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_split.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strtrim.c \
	get_path.c \
	count_argc.c \
	get_params.c \
	ft_strnstr.c \
	add_command.c \

OBJS = ${SRCS:.c=.o}

LIB = rediredtions.a

REM = rm -f

ARV = ar -rcs

.c.o :
	${CC} ${CFLAGS} $< -o $@
	${ARV} $(LIB) $@

all : $(LIB)
$(LIB) : $(OBJS)
	cc ${CFLAGS} rediredtions.c ${LIB} -o execute

clean :
	${REM} ${OBJS} execute

fclean : clean
	${REM} ${LIB}

re : fclean all

.PHONY : all clean fclean re
