#include "main.h"

void cleanup(va_list args, buffer_t *output);
int process_format(const char *format, va_list args, buffer_t *output, int *ret);
int handle_percent(const char *format, va_list args, buffer_t *output, int *i, int *ret);

/**
 * cleanup - Performs cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * process_format - Processes the format string.
 * @format: Character string to print - may contain directives.
 * @args: A va_list of arguments.
 * @output: A buffer_t struct containing a buffer.
 * @ret: Pointer to return value counter.
 *
 * Return: The number of characters stored to output.
 */
int process_format(const char *format, va_list args, buffer_t *output, int *ret)
{
	int i;

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (handle_percent(format, args, output, &i, ret) == -1)
				return (-1);
		}
		else
		{
			*ret += _memcpy(output, (format + i), 1);
		}
	}
	return (*ret);
}

/**
 * handle_percent - Handles '%' directive.
 * @format: Character string to print - may contain directives.
 * @args: A va_list of arguments.
 * @output: A buffer_t struct containing a buffer.
 * @i: Pointer to current index in format string.
 * @ret: Pointer to return value counter.
 *
 * Return: 0 on success, -1 on error.
 */
int handle_percent(const char *format, va_list args, buffer_t *output, int *i, int *ret)
{
	int wid, prec;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *, unsigned char, int, int, unsigned char);

	tmp = 0;
	flags = handle_flags(format + *i + 1, &tmp);
	wid = handle_width(args, format + *i + tmp + 1, &tmp);
	prec = handle_precision(args, format + *i + tmp + 1, &tmp);
	len = handle_length(format + *i + tmp + 1, &tmp);

	f = handle_specifiers(format + *i + tmp + 1);
	if (f != NULL)
	{
		*i += tmp + 1;
		*ret += f(args, output, flags, wid, prec, len);
	}
	else if (*(format + *i + tmp + 1) == '\0')
	{
		return (-1);
	}

	return (0);
}

/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @args: A va_list of arguments.
 * @output: A buffer_t struct containing a buffer.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int ret = 0;

	if (process_format(format, args, output, &ret) == -1)
		return (-1);

	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);

	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}

