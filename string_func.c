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

