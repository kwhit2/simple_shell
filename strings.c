#include "shell.h"

/**
  * _strcmp - compares two strings
  * @s1: string 1
  * @s2: string 2
  * Return: difference
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}

/**
  * _strcat - concatenate two strings
  * @dest: return string
  * @src: source
  * Return: dest
  */
char *_strcat(char *dest, char *src)
{
	int i, k;

	i = k = 0;
	while (*(dest + i))
		i++;
	while ((*(dest + i) = *(src + k)))
	{
		i++;
		k++;
	}
	return (dest);
}

/**
  * _strcpy - copy src to dest
  * @dest: return
  * @src: source
  * Return: dest
  */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}

/**
  * _strlen - get string length
  * @s: string
  * Return: length
  */
int _strlen(char *s)
{
	int ln;

	ln = 0;
	while (s[ln] != '\0')
		ln++;

	return (ln);
}

/**
  * _strdup - duplicate string
  * @str: string
  * Return: pointer to duplicate
  */
char *_strdup(char *str)
{
	char *new;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;

	new = malloc(sizeof(char) * (len + 1));

	if (new == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new[i] = str[i];
	return (new);
}
