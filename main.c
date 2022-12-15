#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff = NULL;
	size_t read_len;
	ssize_t returned_len;
	
	int p_id;
	char *arg[1024];
	unsigned int i = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
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
	while (i < 2)
	{
		free(arg[i]);
		i++;
	}
	
	return (0);
}
