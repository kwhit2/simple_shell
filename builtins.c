#include "shell.h"

/**
* hsh_cd - CD built in
*
* @args: arguments
*
* Return: 1
*/

int hsh_cd(char **args)
{
	if (args[1] == NULL)
		perror("No argument found\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("hsh\n");
	}
	return (1);
}

/**
* hsh_exit - exit built in
*
* @args: arguments
*
* Return: 0
*/
int hsh_exit(char **args)
{
	args = args;
	return (0);
}

/**
  * hsh_env - print environment
  * @args: unused
  * Return: always 0
  */
int hsh_env(char **args)
{
	int a = 0;

	args = args;
	while (environ[a] != NULL)
	{
		write(STDOUT_FILENO, environ[a], _strlen(environ[a]));
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
	return (1);
}
