#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_strchr(char *s, char c)
{
  while (*s != '\0' && *s != c)
    s++;
  if (*s == c)
    return s;
  else
    return NULL;
}
