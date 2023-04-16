#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _strlen(char *s)
{
  int len = 0;
  while (*s != '\0')
  {
    len++;
    s++;
  }
  return len;
}
