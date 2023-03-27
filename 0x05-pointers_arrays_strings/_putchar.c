#include "main.h"
#include <uinstd.h>

/**
 * _putchar - writes the character c for stdout
 * @c : the character to print
 *
 * Return: On Success 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
