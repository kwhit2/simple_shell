# About
Holberton School project by Finn Aspenson and Kyle Whitten

## Requirments
* Allowed editors: vi, vim, emacs

* All your files should end with a new line

* Your code should use the Betty style

* Your shell should not have any memory leaks

* No more than 5 functions per file

* All your header files should be include guarded

## Permitted Functions and System Calls
* access

* chdir

* close

* closedir

* execve

* exit

* fflush

* fork

* free

* getcwd

* getline

* getpid

* isatty

* kill

* malloc

* open

* opendir

* perror

* read

* readdir

* signal

* stat

* lstat

* fstat

* strtok

* wait

* waitpid

* wait3

* wait4

* write
## Description
In the simple shell project, we must create our own UNIX command line interpreter.

## Files
* shell.c - contains the primary parts of the code, including the main loop

* shell.h - contains the libraries and function prototypes

* _read.c - contains the function for reading a given line

* _parse.c - has the function that parses the given line

* _execute.c - contains setup for builtin functions, the function for 'help', and the execute function

* builtins.c - contains the functions for 'cd' and 'exit'

* chars.c - contains custom putchar, getchar, and puts functions

* strings.c - has custom string functions

* man_1_simple_shell - man page

## Available Builtins

help

env

exit

Ctrl+C does not quit

## Authors
Kyle Whitten and Finn Aspenson
