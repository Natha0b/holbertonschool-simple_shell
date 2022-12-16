#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

void func_strtok(char *buff, char *str_p)
{
	char str[100], *len = str, *n = NULL;
	int i = 0;

	while (str_p[i])
		i++;
	(void)buff;

	strcpy(str, str_p);
	while ((n = strtok(len, ":")) != NULL)
	{
		printf("%s\n", n);
		n = NULL;
	}
}