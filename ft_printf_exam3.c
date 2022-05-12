/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:57:02 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/10 16:21:05 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_putnbr(unsigned int digit, int base)
{
	char *temp = "0123456789abcdef";
	int count = 0;
	int n = 0;

	if (digit / base != 0)
		count += ft_putnbr(digit / base, base);
	n = digit % base;
	count += write(1, &temp[n], 1);
	return (count);
}

int ft_format_x(unsigned int digit)
{
	int count = 0;
	int i = 0;
	
	count += ft_putnbr(digit, 16);
	return (count);
}

int ft_format_d(int digit)
{
	int i = 0;
	int count = 0;

	if (digit < 0)
	{
		digit = digit * -1;
		count += write(1, "-", 1);	
	}
	count += ft_putnbr(digit, 10);
	return (count);
}

char ft_format_s(char *str)
{
	int i = 0;
	
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_printf(char *str, ...)
{
	int i = 0;
	int count = 0;

	va_list(args);
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				count += ft_format_s(va_arg(args, char *));
			if (str[i] == 'd')
				count += ft_format_d(va_arg(args, int));
			if (str[i] == 'x')
				count += ft_format_x(va_arg(args, unsigned int));
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

int main(void)
{
	char *str = "coucou";
	int d = -123456789;
	unsigned int x = -123456789;
	
	int res1 = 0;
	int res2 = 0;

	res1 = ft_printf("RESULTAT : %s\n", str);
	res2 = printf("RESULTAT : %s\n", str);
	printf("RES1:%d\n", res1);
	printf("RES2:%d\n\n", res2);

	res1 = ft_printf("RESULTAT : %d\n", d);
	res2 = printf("RESULTAT : %d\n", d);
	printf("RES1:%d\n", res1);
	printf("RES2:%d\n\n", res2);

	res1 = ft_printf("RESULTAT : %x\n", x);
	res2 = printf("RESULTAT : %x\n", x);
	printf("RES1:%d\n", res1);
	printf("RES2:%d\n\n", res2);
}