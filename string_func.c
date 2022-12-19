#include "shell.h"

/**
 *_strcmp - function a string
 *@s1: varible punter
 *@s2: variable punter
 *Return: pointer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		s1++;
		s2++;
	}
	return (0);
}

/**
 **_calloc- function malloc and free
 *@nmemb: variable malloc
 *@size: variable malloc
 *Return: zero
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *a;
	unsigned int i;

	if (nmemb == 0)
	{
		return (NULL);
	}

	if (size == 0)
	{
		return (NULL);
	}

	a = malloc(size * nmemb);

	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size * nmemb; i++)
	{
		a[i] = 0;
	}

	return (a);
}

/**
 **_strcpy - function a string
 *@dest: varible punter
 *@src: varible punter
 *Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (p);
}

/**
 **_getenv - function a string
 *@name: varible punter
 *Return: pointer
 */

char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; __environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; __environ[i][j] != '='; j++)
		{
			if (name[j] != __environ[i][j])
			{
				status = 0;
				break;
			}
		}

		if (status)
		{
			return (&__environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 **_strcat - function a string
 *@dest: varible punter
 *@src: varible punter
 *Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;
	int c;
	int n;
	
	for (c = 0; dest[c]; c++)
	{
	
	}
	
	for (n = 0; src[n]; n++, c++)
	{
		dest[c] = src[n];
	}
	
	dest[c] = '\0';
	return (p);

}