#include "shell.h"

/**
 * main - function main
 * @argc: variable int
 * @arg: variable matriz char
 * Return: int
 */

int main(int argc, char **arg)
{
	char *buff;
	size_t read_len = 0;
	ssize_t returned_len = 0;
	pid_t p_id;
	int status;

	(void)argc;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		returned_len = getline(&buff, &read_len, stdin);
		if (returned_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		buff[returned_len - 1] = '\0';
		if (_strcmp("env", buff) == 0)
			_env();

		arg = func_strtok(buff, " ");
		arg[0] = search_path(arg[0]);
		if (arg[0] != NULL)
		{
			p_id = fork();
			if (p_id == 0)
			{
				if (execve(arg[0], arg, NULL) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					status = WEXITSTATUS(status);
			}
		}
		else
			perror("Error");
	}
	free(arg);
	return (0);
}
