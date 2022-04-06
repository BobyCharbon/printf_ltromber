#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_format_c(va_list args)
{
	char c;
	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int ft_format_s(va_list args)
{
	char *str;
	int i;
	i = 0;
	str = va_arg(args, char *);
	while (str[i] != '\0')
		i++;
	return(write(1, str, sizeof(char) * i));
}

int ft_format(char str, va_list args)
{
	if (str == 'c')
		ft_format_c(args);
	if (str == 's')
		ft_format_s(args);
	return (0);
}

int ft_printf(char *str, ...)
{
	int i = 0;
	int ret = 0;
	va_list args;

	va_start(args, str);
	while(str[i] != '\0')
	{
		if(str[i] != '%')
			ret += write(1, &str[i], 1);
		else
		{
			i++;
			ret += ft_format(str[i], args);
		}
	i++;
	}
	va_end(args);
	return (ret);
}

int main (void)
{
	// char c;
	char *str;
	str = "str";
	// c = 'c';
	ft_printf("%s\n", str);
}