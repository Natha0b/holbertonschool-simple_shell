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
