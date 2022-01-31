/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:46:11 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 13:50:23 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hexcode_xmaj(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('A' + (digit - 10));
}

int	ft_print_xmaj_(unsigned int x)
{
	char	c;
	int count;

	c = hexcode_xmaj(x % 16);
	if (x > 0)
		count = 1 + ft_print_xmaj_(x / 16);
	else
		return (0);
	write(1, &c, 1);
	return (count);
}

int	ft_print_xmaj(unsigned int x)
{
	char	c;
	int count;

	c = hexcode_xmaj(x % 16);
	if (x == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return (ft_print_xmaj_(x));
}