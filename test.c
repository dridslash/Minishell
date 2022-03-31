#include "minishell.h"

int main(int main, char **argv, char **env)
{
	char	**nice;
	t_env	*test;
	char	*str;
	
	nice = malloc(sizeof(char *) * 7);
	nice[0] = malloc(sizeof(char) * 4);
	nice[0] = "cat";
	nice[1] = NULL;
	nice[2] = malloc(sizeof(char) * 8);
	nice[2] = "main.c";
	nice[3] = malloc(sizeof(char) * 3);
	nice[3] = "|";
	nice[4] = NULL;
	nice[5] = malloc(sizeof(char) * 3);
	nice[5] = "ls";

	char	**new;

	new = remove_null(nice, 7);
	system("leaks a.out");
}
