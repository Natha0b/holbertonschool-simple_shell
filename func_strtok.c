#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

char **func_strtok(char *str_p)
{
	char *n = NULL;
	int i = 0, j = 0;
	char **array_path;

	array_path = (char **)malloc(sizeof(char *) * 1024);

	if (!array_path)
		return (NULL);

	while (str_p[i])
		i++;

	while ((n = strtok(str_p, ":")) != NULL)
	{
		if (!n)
			break;
		printf("%s\n", n);
		array_path[j] = n;
		str_p = NULL;
		j++;
	}
	return(&(*array_path));
}