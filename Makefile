



all : 
	gcc -Wall -Wextra -Werror main.c  error_functions.c -lreadline split_input.c
