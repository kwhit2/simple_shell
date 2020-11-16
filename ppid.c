#include <stdio.h>
#include <unistd.h>

/**
  * ppid - PID
  *
  * Return: Always 0.
  */
int ppid(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
