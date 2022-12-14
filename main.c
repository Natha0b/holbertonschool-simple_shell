#include "shell.h"

/**
 * main - function main
 * @void: variable void
 * Return: int
 */

int main(void)
{
	char *buff = NULL;
	size_t read_len = 0;
	ssize_t returned_len;

	while (1)
	{
		printf("$ ");
		returned_len = getline(&buff, &read_len, stdin);
		buff[returned_len - 1] = '\0';
		printf(" %s\n", buff);

		if (!strcmp("exit", buff) != 0)
			break;
		
		
	}

	return (0);
}
