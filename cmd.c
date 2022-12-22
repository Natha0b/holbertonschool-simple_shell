#include "shell.h"

/**
 * execute_env - function execute the process
 * @arg: variable char
 * Return: void
*/

int execute_env(char **arg)
{
	pid_t p_id;
	int status;

	arg[0] = search_path(arg[0]);
	if (arg[0] != NULL)
	{
		p_id = fork();
		if (p_id == 0)
		{
			if (execve(arg[0], arg, environ) == -1)
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
		perror("Error:");

	free(arg);
	return (status);
}
