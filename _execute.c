#include "shell.h"

int _strcmp(char *s1, char *s2);

char *builtin_cmd[] = {
	"cd",
	"help",
	"exit",
	"env"
};

int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit,
	&hsh_env
};

/**
* hsh_num_builtins - num built in
*
* Return: size of & contents of char *
*/
int hsh_num_builtins(void)
{
	return ((sizeof(builtin_cmd)) / sizeof(char *));
}

/**
* hsh_help - help built in
*
* @args: arguments
*
* Return: 1
*/
int hsh_help(char **args)
{
	int i;

	my_puts("Finn Aspenson and Kyle Whitten's simple shell");
	my_puts("Type command names and arguments, then hit enter");
	my_puts("The following commands have been built in:\n");
	for (i = 0; i < hsh_num_builtins(); i++)
		my_puts(" builtin_cmd[i]\n");
	args = args;
	my_puts("Use man command for more info.\n");
	return (1);
}

/**
  * hsh_execute - execute
  * @args: passed arguments
  * Return: launch
  */
int hsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (hsh_launch(args));
}
