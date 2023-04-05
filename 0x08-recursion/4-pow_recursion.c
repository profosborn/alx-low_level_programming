#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: the base value
 * @y: the number raised to the power
 *
 * Return: If y > 0 - the pow_recursion .
 *         If y < 0 - -1 to indicate an error
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	else if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
