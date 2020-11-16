#ifndef LIB_H
#define LIB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int lsh_help(char **args);
int size_builtins(void);
void lsh_loop(void);
int lsh_execute(char **args);
int lsh_launch(char **args);
char **_parse(char *line);
char *_read(void);
int lsh_cd(char **args);
int lsh_exit(char **args);
int printenv(int ac, char **av, char **env);
int env(int ac, char **av, char **env);
int status(int ac, char **av);
int forkwaitexec(void);
int ppid(void);
int pid(void);
int _putchar(char c);
int _getchar(void);
void my_puts(char *s);

#endif
