#include "shell.h"

/**
 * main - function main
 * @argc: variable int
 * @arg: variable matriz char
 * @environ: variable char
 * Return: int
 */

int main(int argc, char **arg, char **environ)
{
	char *buff = NULL;
	size_t read_len = 0;
	ssize_t get_len = 0;

	(void)argc;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		/* read the command line */
		get_len = getline(&buff, &read_len, stdin);
		/* if it fails we release and break the loop */
		if (get_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		/* the null is removed at the end of the read line */
		buff[get_len - 1] = '\0';
		/* we compare that the word env is equal to the command */
		if (_strcmp("env", buff) == 0)
			_env();
		/* we split the path of the command */
		arg = func_strtok(buff, " ");
		execute_env(arg, environ);
	}
	return (0);
}
