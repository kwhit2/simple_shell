#define _BUF_ 1024
#include "shell.h"
/**
  * _read - reads the line given
  * Return: 0
  */

char *_read(void)
{
	int bufsize = _BUF_;
	int pos = 0, c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		c = _getchar();

		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			return (buffer);
		}
		else
			buffer[pos] = c;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += _BUF_;
			buffer = _realloc(buffer, bufsize, bufsize);
			if (!buffer)
			{
				perror("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
