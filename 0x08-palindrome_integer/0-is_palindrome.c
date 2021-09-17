#include "palindrome.h"

/**
 * is_palindrome - Function that checks whether or not a
 * given unsigned integer is a palindrome.
 * @n: unsigned long integer
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	int rest, num, flip = 0;

	num = n;

	while (n != 0)
	{
		rest = n % 10;
		flip = flip * 10 + rest;
		n = n / 10;
	}
	if (num == flip)
		return (1);
	else
		return (0);
}
