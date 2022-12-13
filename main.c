#include "shell.h"

int main()
{
	while (1)
	{
		char command[100];
		printf("$ ");
		scanf(" %99[^\n]", command);
		if (!strcmp("exit", command))
		{
			break;
		}
	}
	return (0);
}
