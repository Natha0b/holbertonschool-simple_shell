#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff = NULL;
	size_t read_len = 0;
	ssize_t returned_len;
	int file_d = 0;
	int p_id;
	char *arg[1024];

	while (1)
	{
		if (isatty(file_d))
			printf("$ ");

		returned_len = getline(&buff, &read_len, stdin);

		buff[returned_len - 1] = '\0';

		arg[0] = buff;
		arg[1] = NULL;

		if (strcmp("exit", buff) == 0)
			break;

		if (returned_len == -1)
			break;
		p_id = fork();

		if (p_id == 0)
		{
			if (execve(buff, arg, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait(NULL);

	}

	return (0);
}