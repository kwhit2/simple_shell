#define _BUFSIZE 64
#define _DELIM " \t\r\n\a"
#include "shell.h"
#include "strings.h"
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
		fprintf(stderr, "allocation error\n");
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
			toks = realloc(toks, buf * sizeof(char *));
			if (!toks)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, _DELIM);
	}
	toks[pos] = NULL;
	return (toks);
}
