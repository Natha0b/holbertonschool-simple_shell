#include "shell.h"

/**
 * func_strtok - function separates with a delimiter
 * @str_p: variable char
 * @delim: variable char
 * Return: char
 */

char **func_strtok(char *str_p, char *delim)
{
	char *split, **array_path;
	int i = 0, j = 0;

	array_path = (char **)malloc(sizeof(char *) * 100);
	if (!array_path)
		return (NULL);
	while (str_p[i])
		i++;
	while ((split = strtok(str_p, delim)) != NULL)
	{
		array_path[j] = split;
		str_p = NULL;
		j++;
	}
	array_path[j] = NULL;
	return (array_path);
}

/**
 * search_path - function search in the path
 * @command: variable char
 * Return: char
 */

char *search_path(char *command)
{
	char *found_path, **array_path, *cpy;
	int len_root, aux = 0, i = 0;
	struct stat info;
	char *str_path = _getenv("PATH");

	if (stat(command, &info) == 0)
		return (command);
	cpy = malloc(strlen(str_path) + 1);
	cpy = strcpy(cpy, str_path);
	array_path = func_strtok(cpy, ":");
	while (array_path[i] != NULL)
	{
		len_root = strlen(array_path[i]);
		if (array_path[i][len_root - 1] != '/')
			found_path = strcat(array_path[i], "/");

		found_path = strcat(array_path[i], command);
		if (stat(found_path, &info) == 0)
		{
			aux = 1;
			break;
		}
		i++;
	}
	if (!aux)
		return (NULL);
	free(array_path);
	free(cpy);
	return (found_path);
}
