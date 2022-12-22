#include "shell.h"

/**
 **_getenv - function a string
 *@name: varible punter
 *Return: pointer
 */

char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		/* recorre las rutas y valida la variable de entorno */
		for (j = 0; environ[i][j] != '='; j++)
		{
			/* si el comando es diferente a la ruta/comando sale con 0 */
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}

		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * _env - function print the environ variables
 * @void: variable void
 * Return: void
 */

void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
