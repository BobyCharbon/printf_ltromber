/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:41:35 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/24 14:10:17 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hexcode(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('a' + (digit - 10));
}

int	ft_print_x_(unsigned int x)
{
	char	c;
	int		count;

	count = 0;
	c = hexcode(x % 16);
	if (x > 0)
		count = 1 + ft_print_x_(x / 16);
	else
		return (0);
	write(1, &c, 1);
	return (count);
}

int	ft_print_x(unsigned int x)
{
	char	c;
	int		count;

	count = 0;
	c = hexcode(x % 16);
	if (x == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return (ft_print_x_(x));
}
