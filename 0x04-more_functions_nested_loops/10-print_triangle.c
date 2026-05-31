#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int row, col, space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		/* Print spaces */
		for (space = size - row; space > 0; space--)
		{
			_putchar(' ');
		}

		/* Print # */
		for (col = 1; col <= row; col++)
		{
			_putchar('#');
		}

		_putchar('\n');
	}
}
