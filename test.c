#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char **argv, char **env)
{
	char *comm[3] = {"cat", "saads", NULL};
	int status;

	if (fork() == 0)
	{
		execve("/bin/cat", comm, env);
	}
	else
	{
		printf("Main priocess here\n");
	wait(&status);
	}
	printf("Status is : %d\n", status);
}
