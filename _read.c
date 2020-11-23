#include "shell.h"
/**
  * _read - reads the line given
  * Return: 0
  */

char *_read(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
