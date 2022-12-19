#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff, *found_path;
	size_t read_len = 120;
	ssize_t returned_len;
	int file_d = 0, status = 0, p_id, i = 0;
	char *arg[1024], **array_path = NULL;

	while (1)
	{
		if (isatty(file_d))
			printf("$ ");

		if (buff == NULL)
			return (1);

		returned_len = getline((char **)&buff, &read_len, stdin);
		if (returned_len == -1)
			break;
		buff[returned_len - 1] = '\0';

		arg[0] = buff;
		arg[1] = '\0';

		if (_strcmp("exit", buff) == 0)
			break;


		found_path = search_path(buff);
		printf("%s\n", found_path);
		p_id = fork();

		if (p_id == 0)
		{
			if (execve(found_path, arg, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait(&status);
	}

	free(buff);
	return (0);
}
