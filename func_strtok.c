#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

char **func_strtok(char *str_p)
{
	char *split, **array_path;
	int i = 0;

	split = strtok(str_p, ":");
	array_path = (char **)malloc(sizeof(char *) * 1024);

	if (!array_path)
	{
		free(array_path);
		return (NULL);
	}

	while (split)
	{
		array_path[i] = split;
		str_p = NULL;
		i++;
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

	cpy = malloc(strlen(str_path) + 1);
	cpy = _strcpy(cpy, str_path);
	array_path = func_strtok(cpy);
	while (array_path[i])
	{
		len_root = strlen(array_path[i]);
		if (array_path[i][len_root - 1] == '/')
		{
			found_path = _strcat(array_path[i], command);
			printf("%s\n", found_path);
		}
		else
		{
			found_path = _strcat(array_path[i], "/");
			found_path = _strcat(found_path, command);
			printf("%s\n", found_path);
		}
		if (stat(found_path, &info) == 0)
			break;
		i++;
	}
	printf("%s\n", found_path);
	return (found_path);
}
