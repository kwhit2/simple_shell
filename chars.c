#include "shell.h"

/**
  * _putchar - replicate putchar
  * @c: character to print
  * Return: char
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _getchar - replicate getchar
  * Return: char
  */
int _getchar(void)
{
	return (getc(stdin));
}

/**
  * my_puts - replicate puts
  * @s: string to print
  */
void my_puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		write(1, &s[i], 1);
	write(1, "\n", 1);
}
