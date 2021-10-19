#include "ft_printf.c"

int	ft_conversion(va_list vl, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(vl, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(vl, char*));
	else if (format == 'p')
		char_printed += ft_putptr(va_arg(vl, unsigned long long));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(vl, int));
	else if (format == 'u')
		char_printed += ft_putunbr(va_arg(vl, unsigned int));
	else if (format == 'x' || foarmat == 'X')
		char_printed += ft_puthex(va_arg(vl, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar(va_arg(vl, char));
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	vl;
	int	char_printed;

	i = 0;
	char_printed = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_conversion(vl, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
