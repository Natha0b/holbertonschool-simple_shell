#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(int argc, char **arg, char **env)
{
	char *buff;
	size_t read_len = 120;
	ssize_t returned_len;
	int p_id, i = 0, status = 0;

	(void)argc;
	while (1)
	{
		if (isatty(0))
			printf("$ ");

		returned_len = getline((char **)&buff, &read_len, stdin);
		if (returned_len == -1)
			break;
		buff[returned_len - 1] = '\0';
		if (_strcmp("exit", buff) == 0)
			break;
		arg = func_strtok(buff, " ");
		arg[0] = search_path(arg[0]);
		p_id = fork();
		if (p_id == 0)
		{
			if (execve(arg[0], arg, env) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait(&status);
	}
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	return (0);
}
