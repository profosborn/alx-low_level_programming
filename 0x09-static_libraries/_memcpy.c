#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
  unsigned int i;
  for (i = 0; i < n; i++)
    dest[i] = src[i];
  return dest;
}
