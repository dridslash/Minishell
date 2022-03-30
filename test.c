#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
int main(int argc, char **argv, char **env)
{
	char *string;

	string = readline("$> ");
	system("leaks a.out");
}
