#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

void func_strtok(char *buff)
{
	char *arg[100], *str_p = getenv("PATH");
	char str[100], *len = str, *n = NULL;
	int i;

	while (str_p[i])
		{
			i++;
		}

		if (strcmp(buff, "PATH") == 0)
		{

			strcpy(str, str_p);
			while ((n = strtok(len, ":")) != NULL)
			{
				printf("%s\n", n);
				n = NULL;
			}
		}
}