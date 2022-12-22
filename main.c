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
		/* lee la linea de comando */
		returned_len = getline(&buff, &read_len, stdin);
		/* si falla liberamos y rompemos el ciclo */
		if (returned_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		/* se quita el nullo al final de la linea leida */
		buff[returned_len - 1] = '\0';
		/* comparamos que la palabra env sea igual al comando */
		if (_strcmp("env", buff) == 0)
			_env();
		/* dividimos la ruta de el comando */
		arg = func_strtok(buff, " ");
		/* llamamos a path y le pasamos el primer el comando */
		arg[0] = search_path(arg[0]);
		if (arg[0] != NULL)
		{
			/* creamos el proceso hijo */
			p_id = fork();
			/* si el proceso hijo falla imprimimos un error si no se ejecuta el comando*/
			if (p_id == 0)
			{
				if (execve(arg[0], arg, NULL) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				/* esperamos que el proceso hijo muera */
				wait(&status);
				if (WIFEXITED(status))
					status = WEXITSTATUS(status);
			}
		}
		/* si el proceso hijo falla imprimimos error */
		else
			perror("Error:");
		free(arg);
	}
	return (0);
}
