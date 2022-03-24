#include "exec_test.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env *list;

	ft_env(&list);
	while (list != NULL)
	{
		printf("%s\n", list->path_env);
		list = list->next_env;
	}
	printf("\n\n");
	printf("Input with dollar : %s\n", search_in_env(&list, argv[1]));

}
