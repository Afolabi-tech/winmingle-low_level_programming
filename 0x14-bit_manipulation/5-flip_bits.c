#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to
 * flip to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	unsigned int count;

	diff = n ^ m; /* XOR - 0 if both numbers are the same and 1 if not  */
	count = 0;

	while (diff)
	{
		diff &= (diff - 1);
		count++;
	}

	return (count);
}
