#include "main.h"
/**
 * _isalpha - checks for alphabetic character
 *@c: the characters mention
 * Return: 1 if c is letter, lowercase or uppercase 0 therwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
