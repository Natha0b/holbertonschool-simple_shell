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

	while (str_p[i])
		{
			i++;
		}

		if (strcmp(buff, "PATH") == 0)
		{

			strcpy(str, string_path);
			while ((n = strtok(len, ":")) != NULL)
			{
				printf("%s\n", n);
				n = NULL;
			}
		}
}