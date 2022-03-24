#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
	execve(NULL, NULL, env);
	printf("Errno is : %d\n", errno);
}
