#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_memset(char *s, char b, unsigned int n)
{
  unsigned int i;
  for (i = 0; i < n; i++)
    s[i] = b;
  return s;
}
