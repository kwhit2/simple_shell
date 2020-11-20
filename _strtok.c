#include "shell.h"

/**
* _strtok - divides the string into tokens
*
* @str: string
* @del: delimeter
*
* Return: a pointer to the next token or NULL if there are no more tokens
*/

char *_strtok(char *str, const char *del)
{
	int i, j;
	char *tok;

	for (i = 0; tok[i] < str && str[i] != '\0'; i++)
	{
		for (j = 0; tok[j] < del && del[j]; j++)
		{
			if (str[i] == del[j])
				str[i] = '\0';
			tok = str;
		}
	}
return (str);
}
