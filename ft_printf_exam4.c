/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:42:37 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/15 14:16:31 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putnbr(unsigned int digit, int base)
{
	char *tab = "0123456789abcdef";
	int count = 0;
	int n = 0;
	
	if(digit / base != '\0')
		count += ft_putnbr(digit / base, base);
	n = digit % base;
	count += write(1, &tab[n], 1);
	return (count);
}

int ft_format_s(char *str)
{
	int i = 0;
	
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
		i++;
	write(1, str, sizeof(char) * i);
	return (i);
}

int ft_format_d(int digit)
{
	int count = 0;
	int i = 0;

	if(digit < 0)
	{
		digit = digit * -1;
		count += write(1, "-", 1);
	}
	count += ft_putnbr(digit, 10);
	return(count);
}

int ft_printf(char *str, ...)
{
	int count = 0;
	int i = 0;
	va_list (args);
	va_start(args, str);
	
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				count += ft_format_s(va_arg(args, char *));
			if(str[i] == 'd')
				count += ft_format_d(va_arg(args, int));
			if(str[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
			
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return(count);
}

int main(void)
{
	char *str = "coucou";
	int d = 1234567;
	unsigned int x = 1234567;
	int res1 = 0;
	int res2 = 0;

	res1 = ft_printf("RESULTAT:%s\n", str);
	res2 = printf("RESULTAT:%s\n", str);
	printf("%d\n", res1);
	printf("%d\n", res2);
	
	res1 = ft_printf("RESULTAT:%d\n", d);
	res2 = printf("RESULTAT:%d\n", d);
	printf("%d\n", res1);
	printf("%d\n", res2);
	
	res1 = ft_printf("RESULTAT:%x\n", x);
	res2 = printf("RESULTAT:%x\n", x);
	printf("%d\n", res1);
	printf("%d\n", res2);
}