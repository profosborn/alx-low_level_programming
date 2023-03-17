#include <stdio.h>
#include <ctype.h>
/**
 * main - prints all single digit numbers of
 * starting from followed by a new line
 * Return: Always 0
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
		printf("%d", n);
	printf("\n");
	return (0);
}
