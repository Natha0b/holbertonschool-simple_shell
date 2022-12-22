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

	array_path = (char **)_calloc(100, sizeof(char *));
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
	return (array_path);
}

/**
 * search_path - function search in the path
 * @command: variable char
 * Return: char
 */

char *search_path(char *command)
{
	char *found_path, **array_path = NULL, *cpy = NULL;
	int len_root, aux = 0, i = 0;
	struct stat info;
	char *str_path = _getenv("PATH");

	/* validates that the path sent is the same as the command */
	if (stat(command, &info) == 0)
		return (command);

	cpy = malloc(_strlen(str_path) + 1);
	/* path copy */
	cpy = _strcpy(cpy, str_path);
	/* split the path with a delimiter */
	array_path = func_strtok(cpy, ":");
	/* the path is traversed */
	while (array_path[i] != NULL)
	{
		len_root = _strlen(array_path[i]);
		if (array_path[i][len_root - 1] != '/')
			found_path = _strcat(array_path[i], "/");

		found_path = _strcat(array_path[i], command);
		/* if it finds the command it exits with 1 */
		if (stat(found_path, &info) == 0)
		{
			aux = 1;
			break;
		}
		i++;
	}
	free(cpy);
	free(array_path);
	/* if not found it returns null */
	if (!aux)
		return (NULL);
	return (found_path);
}
