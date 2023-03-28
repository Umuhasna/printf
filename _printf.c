#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

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
				else if (format[i + 1] == '\0')
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
	}

	va_end(list);

}
