#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

char **func_strtok(char *str_p)
{
	char *n;
	int i = 0, j = 0;
	char **array_path;

	array_path = (char **)malloc(sizeof(char *) * 1024);

	if (!array_path)
	{
		free(array_path);
		return (NULL);
	}

	while ((n = strtok(str_p, ":")) != NULL)
	{
		if (!n)
			break;
		array_path[j] = n;
		str_p = NULL;
		j++;
	}
	return (&(*array_path));
}

/**
 * search_path - function search in the path
 * @command: variable char
 * Return: char
 */

char *search_path(char *command)
{
	char *found_path, **array_path, *cpy = NULL;
	int len_root, i = 0;
	struct stat info;
	char *str_path = _getenv("PATH");

	cpy = _strcpy(cpy, str_path);
	array_path = func_strtok(cpy);
	/*good*/
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
	return (found_path);
}
