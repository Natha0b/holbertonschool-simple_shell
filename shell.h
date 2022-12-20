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

char **func_strtok(char *str_p, char *delim);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
char *search_path(char *command);
#endif
