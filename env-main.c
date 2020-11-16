#include <stdio.h>

/**
  * env - prints the environment
  * @ac: count
  * @av: arguments
  * @env: environment
  * Return: Always 0.
  */
int env(int ac, char **av, char **env)
{
	unsigned int i;

	ac = ac;
	*av = *av;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
