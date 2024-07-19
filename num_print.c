#include "main.h"

/**
 * num_print - print num
 * @args: pointer
 * Return: size
 */
int num_print(va_list args)
{
	int size, div, va;
	unsigned int num;

	va = va_arg(args, int);
	size = 0;
	div = 1;
	if (va < 0)
	{
		size += _putchar('-');
		num = va * -1;
	}
	else
		num = va;

	for (; num / div > 9;)
		div *= 10;

	for (; div != 0;)
	{
		size += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (size);
}
/**
 * unsigned_num - check the code
 * @args: pointer
 * Return: size
 */
int unsigned_num(va_list args)
{
	int size, div, va;
	unsigned int num;

	va = va_arg(args, int);
	size = 0;
	div = 1;
	num = va;

	for (; num / div > 9;)
		div *= 10;

	for (; div != 0;)
	{
		size += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (size);
}
