#include "shell.h"

/**
* lsh_cd - CD built in
*
* @args: arguments
*
* Return: 1
*/

int lsh_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "No argument found\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("hsh");
	}
	return (1);
}

/**
* lsh_exit - exit built in
*
* @args: arguments
*
* Return: 0
*/

int lsh_exit(char **args)
{
	(void)args;
	return (0);
}
