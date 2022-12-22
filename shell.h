#ifndef SHELL_H
#define SHELL_H

/* LIBRERAIES */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/* PROTOTYPES */

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strlen(char *s);
int execute_env(char **arg);
char **func_strtok(char *str_p, char *delim);
char *search_path(char *command);
char *_getenv(const char *name);
void _env(void);
#endif
