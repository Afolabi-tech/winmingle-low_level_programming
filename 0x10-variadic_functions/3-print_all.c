#include "variadic_functions.h"
#include <stdio.h>
 

/**
 * print_all - prints anything
 * @format: list of types of arguments passed
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list list;
	unsigned int i = 0;
	char *separator = "";
	char *str;

	va_start(list, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", separator, va_arg(list, int));
			separator = ", ";
		}
		if (format[i] == 'i')
		{
			printf("%s%d", separator, va_arg(list, int));
			separator = ", ";
		}
		switch (format[i])
		{
			case 'f':
				printf("%s%f", separator, va_arg(list, double));
				separator = ", ";
				break;
			case 's':
				str = va_arg(list, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", separator, str);
				separator = ", ";
				break;
			default:
				break;
		}
		i++;
	}

	printf("\n");
	va_end(list);
}
