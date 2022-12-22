#include "shell.h"

/**
 * execute_env - function execute the process
 * @arg: variable char
 * @environ: variable char
 * Return: void
*/

int execute_env(char **arg, char **environ)
{
	pid_t p_id;
	int status;

	/* we call path and pass the first command to it */
	arg[0] = search_path(arg[0]);
	if (arg[0] != NULL)
	{
		/* we create the child process */
		p_id = fork();
		/* if the child process fails we print an error*/
		/*if the command is not executed. */
		if (p_id == 0)
		{
			if (execve(arg[0], arg, environ) == -1)
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
	return (status);
}
