#ifndef SHELL_H
#define SHELL_H

/* LIBRERAIES */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/* PROTOTYPES */


int main(void);
void func_strtok(char *buff, char *str_p);
int _strcmp(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcpy(char *dest, char *src);

#endif
