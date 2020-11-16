#include <stdio.h>
#include <unistd.h>
/**
  * printenv - prints environment
  * @ac: count
  * @av: arguments
  * @env: environment
  * Return: 0
  */

int printenv(int ac, char **av, char **env)
{
	ac = ac;
	*av = *av;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
