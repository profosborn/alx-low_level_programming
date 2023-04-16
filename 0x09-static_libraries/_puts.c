#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

void _puts(char *s)
{
  while (*s != '\0')
  {
    write(1, s, 1);
    s++;
  }
  write(1, "\n", 1);
}
