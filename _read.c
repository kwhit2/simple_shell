#define _BUF_ 1024
#include "shell.h"
/**
  * _read - reads the line given
  * Return: 0
  */

char *_read(void)
{
	char *line = NULL;
	size_t buf = 0;

	if (getline(&line, &buf, stdin) == -1)
	{
		if (getline(&line, &buf, stdin) == EOF)
			exit(EXIT_SUCCESS);
		else
		{
			perror("Could not read line");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
