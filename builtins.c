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

/**
  * lsh_env - print environment
  * @args: unused
  * Return: always 0
  */
int lsh_env(char **args)
{
	int a = 0;
	(void)args;

	while (environ[a] != NULL)
	{
		write(STDOUT_FILENO, environ[a], _strlen(environ[a]));
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
	return (0);
}
