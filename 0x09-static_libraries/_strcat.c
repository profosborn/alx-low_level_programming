#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

char *_strcat(char *dest, char *src)
{
  char *ptr = dest;
  while (*dest != '\0')
    dest++;
  while (*src != '\0')
  {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return ptr;
}
