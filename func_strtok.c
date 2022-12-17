#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

char **func_strtok(char *buff, char *str_p)
{
	char str[100], *len = str, *n = NULL;
	int i = 0, j = 0;
	char **array_path;

	array_path = (char **)malloc(sizeof(char *) * 1024);

	if (!array_path)
		return (NULL);

	while (str_p[i])
		i++;
	(void)buff;

	strcpy(str, str_p);
	while ((n = strtok(len, ":")) != NULL)
	{
		printf("%s\n", n);
		len = NULL;
		array_path[j] = n;
		str_p = NULL;
		j++;
	}
	return(&(*array_path));
}