/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:13 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/13 18:51:29 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_putnbr(unsigned int digit, int base)
{
	int n = 0;
	int i = 0;
	int count = 0;
	char *tab = "0123456789abcdef";
	
	if (digit / base != '\0')
	{
		count += ft_putnbr(digit / base, base);
	}
	n = digit % base;
	count += write(1, &tab[n], 1);
	return (count);
}
