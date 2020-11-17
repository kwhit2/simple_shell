#include "shell.h"
#include "strings.h"
int _strcmp(char *s1, char *s2);

char *builtin_cmd[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

/**
* lsh_num_builtins - num built in
*
* Return: size of & contents of char *
*/

int lsh_num_builtins(void)
{
	return ((sizeof(builtin_cmd)) / sizeof(char *));
}

/**
* lsh_help - help built in
*
* @args: arguments
*
* Return: 1
*/

int lsh_help(char **args)
{
	int i;

	my_puts("Finn Aspenson and Kyle Whitten's simple shell");
	my_puts("Type command names and arguments, then hit enter");
	my_puts("The following commands have been built in:\n");
	for (i = 0; i < lsh_num_builtins(); i++)
		printf(" %s\n", builtin_cmd[i]);
	args = args;
	printf("Use man command for more info.\n");
	return (1);
}

/**
  * lsh_execute - execute
  * @args: passed arguments
  * Return: launch
  */

int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (lsh_launch(args));
}
