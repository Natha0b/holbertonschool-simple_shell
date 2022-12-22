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

/**
*_calloc - function allocates memory
*@nmemb: variable
*@size: variable
*Return: zero
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arr = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	arr = malloc(nmemb * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
	{
		arr[i] = 0;
	}
	return (arr);
}

/**
*_strlen - function
*@s: variable
*Return: int
*/

int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
