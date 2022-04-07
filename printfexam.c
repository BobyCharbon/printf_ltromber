#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	format_d(int i);
int	format_s(char *s);
int	ft_printf(char *s, ...);
int	ft_putchar(char c);
int	ft_putnbr(unsigned int i, int base);

int	ft_printf(char *s, ...)
{
	int	count = 0;
	int i = 0;
	va_list	args;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
				count += format_s(va_arg(args, char *));
			if (s[i] == 'd')
				count += format_d(va_arg(args, int));
			if (s[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	format_s(char *s)
{
	int	i = 0;

	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	format_d(int i)
{
	int	count = 0;

	if (i < 0)
	{
		i *= -1;
		count += ft_putchar('-');
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_putnbr(unsigned int i, int base)
{
	char	*arr = "0123456789abcdef";
	int		count = 0;
	int		n;

	if (i / base != 0)
		count += ft_putnbr(i / base, base);
	n = i % base;
	count += write(1, &arr[n], 1);
	return (count);
}

int main (void)
{
	char *s = "str";
	unsigned int x = s;
	int d = -12345;
	
	int ret;
	int ret2;

	ret = printf("X(VRAI) :%x\n", x);
	ret2 = ft_printf("X       :%x\n", x);
	printf("RET VRAI      :%d\n", ret);
	ft_printf("RET MOI       :%d\n\n", ret2);

	ret = printf("D(VRAI) :%d\n", d);
	ret2 = ft_printf("D       :%d\n", d);
	printf("RET VRAI      :%d\n", ret);
	ft_printf("RET MOI       :%d\n\n", ret2);

	ret = printf("S(VRAI) :%s\n", s);
	ret2 = ft_printf("S       :%s\n", s);
	printf("RET VRAI      :%d\n", ret);
	ft_printf("RET MOI       :%d\n\n", ret2);
}