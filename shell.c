#include "shell.h"

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
* @env: env variable
* Return: Always 0.
*/
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)*av;
	(void)*env;
	/* runs command loop */
	hsh_loop();

	return (0);
}

/**
* hsh_loop - main shell loop
*
*
* Return: arguments
*/
void hsh_loop(void)
{
	char *line;
	char **args;
	int status;
	(void)status;

	signal(SIGINT, stop_ctrl);

	while (1)
	{
	if (isatty(STDIN_FILENO))
	{
		_putchar('$');
		_putchar(' ');
	}
	line = _read(); /* three main function calls */
	args = _parse(line);
	status = hsh_execute(line, args);

	free(line);
	free(args);
	}
}

/**
* hsh_launch - launch function
* @args: arguments
* Return: 0
*/
int hsh_launch(char **args)
{
	pid_t pid;
	int stat;
	char *argv[1024];
<<<<<<< HEAD
	
=======

>>>>>>> 12ea75837e69872e6602d3a951b2505b9edd86cf
	argv[0] = args[0];
	argv[1] = NULL;

	pid = fork();
	args = args;

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("simple_shell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("simple_shell");
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}
