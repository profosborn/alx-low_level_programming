#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_strncat(char *dest, char *src, int n)
{
  char *ptr = dest;
  while (*dest != '\0')
    dest++;
  while (*src != '\0' && n > 0)
  {
    *dest = *src;
    dest++;
    src++;
    n--;
  }
  *dest = '\0';
  return ptr;
}
