#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: - first string to append src to.
 * @src: - second string to append to dest.
 * Return: - the joined string thus.
 */

char *_strcat(char *dest, char *src)
{
	int aray = 0, d_count = 0;

	while (dest[aray++])
	{
		d_count++;
	}

	for (aray = 0; src[aray]; aray++)
	{
		dest[d_count++] = src[aray];
	}

	return (dest);
}
