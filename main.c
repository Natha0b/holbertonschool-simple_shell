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
	/*unsigned int i = 0;*/
	char *str_p = getenv("PATH");

	while (1)
	{
		if (isatty(file_d))
			printf("$ ");

		buff = calloc(1024, sizeof(*buff));

		if (buff == NULL)
			return (1);

		returned_len = getline((char **)&buff, &read_len, stdin);
		buff[returned_len - 1] = '\0';

		arg[0] = buff;
		arg[1] = '\0';

		if (strcmp("exit", buff) == 0)
			break;

		if (returned_len == -1)
			break;

		if (strcmp(buff, "PATH") == 0)
			func_strtok(buff, str_p);

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
	/*while (i < 2)
	{
		free(arg[i]);
		i++;
	}*/
	free(buff);
	return (0);
}
