#define _BUFSIZE 64
#define _DELIM " \t\r\n\a"
#include "shell.h"

/**
  * *_realloc - reallocate
  * @ptr: pointer
  * @old_size: current
  * @new_size: new
  * Return: pointer to new space
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);
		return (new);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		new[i] = ((char *)ptr)[i];
	free(ptr);
	return (new);
}

/**
  * _parse - parse given arguments
  * @line: given line
  * Return: tokens
  */
char **_parse(char *line)
{
	int buf = _BUFSIZE, pos = 0;
	char **toks = malloc(buf * sizeof(char *));
	char *tok;

	if (!toks)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, _DELIM);
	while (tok != NULL)
	{
		toks[pos] = tok;
		pos++;

		if (pos >= buf)
		{
			buf += _BUFSIZE;
			toks = _realloc(toks, buf * sizeof(char *), buf * sizeof(char *));
			if (!toks)
			{
				perror("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, _DELIM);
	}
	toks[pos] = NULL;
	return (toks);
}
