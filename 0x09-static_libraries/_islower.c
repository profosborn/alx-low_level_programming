#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _islower(int c)
{
  if (c >= 'a' && c <= 'z')
    return 1;
  else
    return 0;
}
