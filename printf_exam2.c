/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_exam2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:54:05 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/09 18:02:52 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>



int	ft_putnbr(unsigned int digit, int base)
{
	char *temp = "0123456789abcdef";
	int n = 0;
	int count = 0;

	if (digit / base != 0)
	{
		count += ft_putnbr(digit / base, base);
	}
	n = digit % base;
	count += write(1, &temp[n], 1);
	return (count);
}

char ft_format_s(char *str)
	int i = 0;
{

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

ft_format_d(int d)
{
	int i = 0;
}

/* ft_format_x(unsigned int, base)
{
	
} */

int ft_printf(char *str, ...)
{
	int count = 0;
	int i = 0;
	
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
				count += ft_format_d(args, int *);
		/* 	if (str[i] == 'x')
				count += ft_format_x(args, int *, 16); */
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}

	va_end(args);
	return (i);
}

int main(void)
{
	char *str = "coucou";

	ft_printf("RESULTAT: %s\n", str);	
	// printf("RESULTAT: %s\n", str);	
}