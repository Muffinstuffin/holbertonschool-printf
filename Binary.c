#include "main.h"
/**
 * binary - print char
 * @args: pointer
 * Return: size
 */
int binary(va_list args)
{
	int i = 0, j;
	int bin[100];
	unsigned int input;

	input = va_arg(args, int);
	if (input == 0)
	{
		_putchar('0');
		return (1);
	}
	while (input > 0)
	{
		bin[i] = input % 2;
		input = input / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(bin[j] + '0');
	}
	return (i);
}
