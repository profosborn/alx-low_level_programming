#include <unistd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

unsigned int _strspn(char *s, char *accept)
{
  unsigned int count = 0;
  int found;
  while (*s != '\0')
  {
    found = 0;
    for (int i = 0; accept[i] != '\0'; i++)
    {
      if (*s == accept[i])
      {
        found = 1;
        break;
      }
    }
    if (found)
      count++;
    else
      break;
    s++;
  }
  return count;
}
