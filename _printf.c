#include "main.h"

int print_str(char *str);
int handle_S(char *str);

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
				else if (format[i] == 'd' || format[i] == 'i')
					count += printf("%d", va_arg(list, int));
				else if (format[i] == 'u')
					count += printf("%u", va_arg(list, int));
				else if (format[i] == 'o')
					count += printf("%o", va_arg(list, int));
				else if (format[i] == 'x')
					count += printf("%x", va_arg(list, int));
				else if (format[i] == 'X')
					count += printf("%X", va_arg(list, int));
				else if (format[i] == 'p')
					count += printf("%p", va_arg(list, void *));
				else if (format[i] == 'S')
				{
					str = va_arg(list, char *);
					count += handle_S(str);
				}
				else if (format[i] == '\0')
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

int handle_S(char *str)
{
	int i, count = 0;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			putchar('\\');
			putchar('x');
			count += 1;
			count += printf("0%X", str[i]);
		}
		else
		{
			putchar(str[i]);
			count += 1;
		}
	}

	return (count);
}
