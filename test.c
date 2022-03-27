#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
	printf("%s\n", search_in_env());
}
