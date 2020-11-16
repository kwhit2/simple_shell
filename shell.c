#include "shell.h"
#include "strings.h"
/**
  * stop_ctrl - prevent shell from closing with ctrl+c
  * @s: int
  */
void stop_ctrl(int s)
{
	(void)s;
	signal(SIGINT, stop_ctrl);
	_putchar('\n');
}

/**
* main - main shell.c file
* @ac: argument count
* @av: argument
* Return: Always 0.
*/

int main(int ac, char **av)
{
	(void)ac;
	(void)*av;
	/* runs command loop */
	lsh_loop();

	return (EXIT_SUCCESS);
}

/**
* lsh_loop - main shell loop
*
*
* Return: arguments
*/

void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, stop_ctrl);

	do {
	_putchar('$');
	_putchar(' ');
	line = _read(); /* three main function calls */
	args = _parse(line);
	status = lsh_execute(args);

	free(line);
	free(args);
	} while (status);
}

/**
* lsh_launch - launch function
* @args: arguments
* Return: 0
*/

int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int stat;

	pid = fork();
	(void)wpid;

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("_launch");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	perror("_launch");
	}
	else
	{
		do {
			wpid = waitpid(pid, &stat, WUNTRACED);
		}
	while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
return (1);
}
