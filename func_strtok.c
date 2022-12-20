#include "shell.h"

/**
 * func_strtok - function separates with a delimiter
 * @str_p: variable char
 * Return: char
 */

char **func_strtok(char *str_p)
{
	char *split, **array_path;
	int i = 0;

	array_path = (char **)malloc(sizeof(char *) * 100);

	if (!array_path)
	{
		free(array_path);
		return (NULL);
	}
	while ((split = strtok(str_p, ":")) != NULL)
	{
		if (!split)
			break;
		array_path[i] = split;
		str_p = NULL;
		i++;
	}
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
	int len_root, i = 0;
	struct stat info;
	char *str_path = _getenv("PATH");

	cpy = malloc(strlen(str_path) + 1);
	cpy = _strcpy(cpy, str_path);
	array_path = func_strtok(cpy);
	while (array_path[i])
	{
		len_root = strlen(array_path[i]);
		if (array_path[i][len_root - 1] == '/')
		{
			found_path = _strcat(array_path[i], command);
		}
		else
		{
			found_path = _strcat(array_path[i], "/");
			found_path = _strcat(found_path, command);
		}
		if (stat(found_path, &info) == 0)
			break;
		i++;
	}
	free(cpy);
	free(array_path);
	return (found_path);
}
