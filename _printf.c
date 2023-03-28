#include "main.h"

int print_str(char *str);

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char *str;
	unsigned long int i, count = 0;
	va_list list;

	va_start(list, format);
	if (format)
	{
		for (i = 0; i < strlen(format); i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'c')
				{
					putchar(va_arg(list, int));
					count += 1;
				}
				else if (format[i] == 's')
				{
					str = va_arg(list, char *);
					count += print_str(str);
				}
				else if (format[i] == '%')
				{
					putchar('%');
					count += 1;
				}
				else if (*format++)
					return (-1);

				else
				{
					putchar(format[i - 1]);
					putchar(format[i]);
					count += 2;
				}
			}
			else
			{
				putchar(format[i]);
				count += 1;
			}
		}
		va_end(list);
	}
	else
		return (-1);

	return (count);
}

/**
 * print_str - print the string
 * @str: string to be printed
 *
 * Return: number of characters printed
 */
int print_str(char *str)
{
	unsigned long int j, count = 0;

	if (str)
	{
		for (j = 0; j < strlen(str); j++)
		{
			putchar(str[j]);
			count += 1;
		}
	}
	else
	{
		str = "(null)";
		for (j = 0; j < strlen(str); j++)
		{
			putchar(str[j]);
			count += 1;
		}
	}

	return (count);
}
