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

char *_strtok(char *str, char *del)
{
	static char *s;
	static int pos;
	int i = 0;
	int begin = pos;

	if (!str || !del || str[pos] == '\0')
		return (NULL);

	if (str != NULL)
		s = str;

	while (s[pos] != '\0')
	{
		while (del[i] != '\0')
		{
			if (s[pos] == del[i])
			{
				s[pos] = '\0';
				pos = pos + 1;

				if (s[begin] != '\0')
					return (&s[begin]);

				else
				{
					begin = pos;
					pos--;
					break;
				}
			}
			i++;
		}
		pos++;
	}
	s[pos] = '\0';
	if (s[begin] == '\0')
		return (NULL);
	else
		return (&s[begin]);
}
