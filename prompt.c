#include "shell.h"

/**
* _strlen -  returns the length of a string
* @s: string
*
* Description: returns the length of a string
* Return:i
*/

int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
		i++;
{
return (i);
}
}

/**
* prompt - prompt
*
* Return: 0
*/

int prompt(void)
{
	char *prompt = "$ ";
	size_t linesize = 0;
	char *line;
	int charactersRead = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		charactersRead = getline(&line, &linesize, stdin);
		write(STDOUT_FILENO, line, charactersRead);
	}
return (0);
}
