#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff;
	size_t read_len = 120;
	ssize_t returned_len;
	int file_d = 0;
	int p_id;
	int status = 0;
	char *arg[1024];
	char **array_path;
	/*unsigned int i = 0;*/
	char *str_p = _getenv("PATH");
	int i = 0;

	while (1)
	{
		if (isatty(file_d))
			printf("$ ");

		buff = _calloc(1024, sizeof(*buff));

		if (buff == NULL)
			return (1);

		returned_len = getline((char **)&buff, &read_len, stdin);
		buff[returned_len - 1] = '\0';

		arg[0] = buff;
		arg[1] = '\0';

		if (_strcmp("exit", buff) == 0)
			break;

		if (returned_len == -1)
			break;

		if (_strcmp(buff, "PATH") == 0)
			array_path = func_strtok(str_p);

		p_id = fork();

		if (p_id == 0)
		{
			if (execve(buff, arg, NULL) == -1)
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
