#include "ft_printf.c"






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
			char_printed += ft_conversion(vl, str[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
