#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff, *found_path, *arg[1024];
	size_t read_len = 120;
	ssize_t returned_len;
	int p_id, i = 0;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		returned_len = getline((char **)&buff, &read_len, stdin);
		if (returned_len == -1)
			break;
		buff[returned_len - 1] = '\0';
		arg[0] = buff;
		arg[1] = NULL;

		if (_strcmp("exit", buff) == 0)
			break;
		found_path = search_path(buff);
		p_id = fork();
		if (p_id == 0)
		{
			if (execve(found_path, arg, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait(NULL);
	}
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	return (0);
}
