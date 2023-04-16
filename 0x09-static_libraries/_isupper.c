#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _isupper(int c)
{
  if (c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

