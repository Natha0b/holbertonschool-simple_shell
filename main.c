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
		/* read the command line */
		returned_len = getline(&buff, &read_len, stdin);
		/* if it fails we release and break the loop */
		if (returned_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		/* the null is removed at the end of the read line */
		buff[returned_len - 1] = '\0';
		/* we compare that the word env is equal to the command */
		if (_strcmp("env", buff) == 0)
			_env();
		/* we split the path of the command */
		arg = func_strtok(buff, " ");
		/* we call path and pass the first command to it */
		arg[0] = search_path(arg[0]);
		if (arg[0] != NULL)
		{
			/* we create the child process */
			p_id = fork();
			/* if the child process fails we print an error if the command is not executed. */
			if (p_id == 0)
			{
				if (execve(arg[0], arg, NULL) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				/* we expect the son process to die */
				wait(&status);
				if (WIFEXITED(status))
					status = WEXITSTATUS(status);
			}
		}
		/* if the child process fails we print error */
		else
			perror("Error:");
		free(arg);
	}
	return (0);
}
