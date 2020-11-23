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

extern char **environ;
/* string functions */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *tokens);
char *_strdup(char *str);

int hsh_env(char **args);
int hsh_help(char **args);
int size_builtins(void);
void hsh_loop(void);
int hsh_execute(char **args);
int hsh_launch(char **args);
char **_parse(char *line);
char *_read(void);
int hsh_cd(char **args);
int hsh_exit(char **args);
int printenv(int ac, char **av, char **env);
int env(int ac, char **av, char **env);
int status(int ac, char **av);
int forkwaitexec(void);
int ppid(void);
int pid(void);
int _putchar(char c);
int _getchar(void);
void my_puts(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **search_path(char **args);
int get_command(char **args);

#endif
