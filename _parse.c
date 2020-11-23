#define _BUFSIZE 1024
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
  * parse_helper - assist in parsing process
  */
/*
char **search_path(char **args)
{
	int i = 0;
	char *path, **dirs = NULL, *token, *cwd = getcwd(NULL, 0);
	struct stat sb;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], "PATH") == 0)
			return (environ + i);
		i++;
	}
	
	environ[i] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	path = environ[i];
	token = strtok(path, ":");

	while (token != NULL)
	{
		dirs[i] = _strdup(token);
		token = strtok(NULL, ":");
		i++;
	}
	*args = "ls";

	while (dirs[i] != NULL)
	{
		chdir(dirs[i]);
		if (stat(*args, &sb) == 0)
		{
			*args = _strcat(dirs[i], *args);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (args);
}
*/
/**
  * _parse - parse the line that was read
  * @line: given line
  * Return: tokenized string
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

/**
  * get_command - get right command
  * @test: ???
  * Return: funtion
  */
/*
int get_command(char **args)
{
	int i;
	int function;

	builtin builtins[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"help", hsh_help},
		{"cd", hsh_cd},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			function = (builtins[i].func)();
			return (function);
		}
	}
	return (1);
}*/
