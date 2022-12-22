#include "shell.h"

/**
 * main - function main
 * @argc: variable int
 * @arg: variable matriz char
 * @environ: variable char
 * Return: int
 */

int main(int argc, char **environ)
{
	char *buff = NULL, **arg;
	size_t read_len = 0;
	ssize_t get_len = 0;
	int status = 0;

	(void)argc;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		get_len = getline(&buff, &read_len, stdin);
		if (get_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		buff[get_len - 1] = '\0';
		if (_strcmp("env", buff) == 0)
			_env();
		arg = func_strtok(buff, " ");
		status = execute_env(arg, environ);
	}
	return (status);
}
