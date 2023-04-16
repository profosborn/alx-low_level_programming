#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_strpbrk(char *s, char *accept)
{
  while (*s != '\0')
  {
    for (int i = 0; accept[i] != '\0'; i++)
    {
      if (*s == accept[i])
        return s;
    }
    s++;
  }
  return NULL;
}
