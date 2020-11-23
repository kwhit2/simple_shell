#include "shell.h"

int _strcmp(char *s1, char *s2);

char *builtin_cmd[] = {
	/*"cd",*/
	"help",
	/*"exit",*/
	"env",
	"setenv",
	"unsetenv"
};

int (*builtin_func[]) (char **) = {
	/*&hsh_cd,*/
	&hsh_help,
	/*&hsh_exit,*/
	&hsh_env,
	&hsh_setenv,
	&hsh_unsetenv
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
	args = args;

	my_puts("Finn Aspenson and Kyle Whitten's simple shell");
	my_puts("Type command names and arguments, then hit enter");
	my_puts("The following commands have been built in:\n");
	my_puts(" help - display shell bio and commands");
	my_puts(" env - print the environment");
	my_puts(" exit - leave shell");
	my_puts("Use man command for more info.\n");
	return (1);
}

/**
  * hsh_execute - execute
  * @args: passed arguments
  * @line: line/arguments passed from _read
  * Return: launch
  */
int hsh_execute(char *line, char **args)
{
	int i;
	char *ex = "exit";

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (_strcmp(args[0], ex) == 0)
		{
			free(line);
			free(args);
			exit(0);
		}
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
			return (((*builtin_func[i])(args)));
	}
	return (hsh_launch(args));
}
