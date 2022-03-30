



all : 
	gcc main.c  error_functions2.c error_functions.c -lreadline split_input1.c split_input2.c split_input3.c split_input4.c split_input5.c split_input6.c take_input.c exec_test.c dollar_handling1.c dollar_handling2.c dollar_handling3.c split_function.c dollar_handling4.c parsing1.c parsing2.c parsing3.c get_next_line.c get_next_line_utils.c get_utils1.c -D BUFFER_SIZE=10000
