#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
	int count = 0;
	
	va_list args;
	va_start(args, format);

	while (*format) {
		if (*format == '%') {
			format++;
			if (*format == 'c') {
				int c = va_arg(args, int);
				:putchar(c);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                while (*s) {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
