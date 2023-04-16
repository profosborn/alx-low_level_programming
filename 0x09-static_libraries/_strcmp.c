#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _strcmp(char *s1, char *s2)
{
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
  {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
