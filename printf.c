#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* -------------------------------------------------------------------------- */
/*                                    12345                                   */
/* -------------------------------------------------------------------------- */

char ft_putchar(char c);
int ft_convert_x(unsigned int nbr);
int ft_putnbr_x(unsigned int nbr);
int ft_putnbr(int nbr, int base, int car);
int ft_format_x(va_list args);
int ft_format_d(va_list args);
int ft_format_c(va_list args);
int ft_format_s(va_list args);
int ft_format(char str, va_list args);
int ft_printf(char *str, ...);


char ft_putchar(char c)
{
	return(write(1, &c, sizeof(c)));
}

int (ft_convert_x(unsigned int nbr))
{
	char *str;
	int i;
	int nbrtemp;

	if (nbr > 9)
	{
		nbr = nbr / 16;
		nbrtemp = nbr % 16;
	}
	while (nbrtemp <= 9)
	{
		ft_putnbr(nbrtemp);
	}
	return (nbr);
}

int ft_putnbr_x(unsigned int nbr)
{
	char *strnbr;

	if (nbr > 9)
		ft_convert_x(nbr);
	if (nbr < 9)
		ft_putchar(nbr);

	// return(ft_convert_x(nbr));
	return (nbr);
}



int ft_putnbr(int nbr, int base, int car)
{
	int len = 0;
	int i = 0;
	char *str;
	
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	len = ft_strlen(nbr, base);
	str = malloc(sizeof(char) * len + 1)
	while (nbr > 0)
	{
		if (nbr % base > 9)
			str[len--] = car + (nbr % base);
		else
			str[len--] = 48 + (nbr %base);
		nbr = nbr / base;
		i++;
	}
	write(1, str, sizeof(len));
	free(str);
	return (i);
}

int ft_format_x(va_list args)
{
	unsigned int nbr;
	int base = 16;
	int car = 87;
	nbr = va_arg(args, unsigned int);
	return(ft_putnbr(nbr, base, car));
}

int ft_format_xmaj(va_list args)
{
	unsigned int nbr;
	int base = 16;
	int car = 55;

	nbr = va_arg(args, unsigned int);
	return(ft_putnbr(nbr, base, car));
}

int ft_format_d(va_list args)
{
	int nbr = 0;
	nbr = va_arg(args, int);
	return (ft_putnbr(nbr));
}

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
		return (ft_format_c(args));
	if (str == 's')
		return (ft_format_s(args));
	if (str == 'd')
		return (ft_format_d(args));
	if (str == 'x')
		return (ft_format_x(args));
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

	int d = -12345;
	unsigned int x = str;

	// ft_printf("D :%d\n\n", d);

	printf("X(VRAI) :%x\n", x);
	ft_printf("X       :%x\n", x);
}