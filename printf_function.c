#include "main.h"
/**
 * char_print - print char
 * @args: pointer
 * Return: size
 */
int char_print(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
 * pert_print - check the code
 * @args: pointer
 * Return: size
 */
int pert_print(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
/**
 * string_print - check the code
 * @args: pointer
 * Return: size
 */
int string_print(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{

		_putchar(str[i]);
	}
	return (i);
}
