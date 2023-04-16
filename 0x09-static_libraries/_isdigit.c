#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _isdigit(int c)
{
  if (c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}
