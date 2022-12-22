#include "shell.h"

/**
 * main - function main
 * @void: variable
 * Return: int
 */

int main(void)
{
	char *buff = NULL, **arg;
	size_t read_len = 0;
	ssize_t get_len = 0;
	int i, spaces = 1, status = 0;

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
		{
			_env();
			continue;
		}
		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] != ' ')
			{
				spaces = 0;
				break;
			}
		}
		if (spaces == 1)
		{
			status = 0;
			continue;
		}
		arg = func_strtok(buff, " ");
		status = execute_env(arg);
	}
	return (status);
}
