#include "shell.h"
#include "strings.h"

/**
* _strtok - divides the string into tokens
*
*@str: string
*@del: delimeter
*
* Return: a pointer to the next token or NULL if there are no more tokens
*/

char *_strtok(char *s, const char *del)
{
	static char *tok;
	int i;

	if (s == 0)
		s = tok;
	do {
		if ((i = *s++) == '\0')
			return (0);
	}
	while (strchr(del, i))
	s--;
	tok = s + strcspn(s, del);
	if (*tok != 0)
		*tok++ = 0;
	return (s);
}

/*
char *_strtok(char *str, const char *del)
{
	int i = 0, len = _strlen(del);
	char *sp = NULL;

	if (len == 0 || (!str && !sp))
		return (NULL);
	if (str && !sp)
		sp = str;
char *p_start = sp;
	while (p_start)
	{
		for (i = 0; i < len; i++)
		{
			if (*p_start == del[i])
			{
				p_start++, break;
			}
		}
	}
	if (i == len)
	{
		sp = p_start;
		break;
	}
	if (*sp == '\0')
	{
		sp = NULL;
		return (sp);
	}
	while (*sp != '\0')
	{
		for (i = 0; i < len; i++)
		{
			if (*sp == del[i])
			{
				*sp = '\0';
				break;
			}
		}
	}
	sp++;
		if (i < len)
			break;
	}
return (p_start);
}
*/
