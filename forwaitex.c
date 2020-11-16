#include "shell.h"
/**
* forkwaitexec - fork, execve & wait functions combined
*
* Return: void
*/

int forkwaitexec(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	pid_t child_pid;

	int i = 0;

	for (; i < 5; i++)
	{
	child_pid = fork();

	if (child_pid == -1)
	{
	perror("Error");
		return (1);
	}

	if (child_pid == 0)
	{

	if (execve(argv[0], argv, NULL) == -1)
	{
	perror("Error:");
	}
	}
	else
	{
	wait(NULL);
}
}
return (0);
}
