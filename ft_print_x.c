/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:41:35 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 13:45:36 by ludovictrom      ###   ########.fr       */
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
	int count;

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
	int count;

	count = 0;
	c = hexcode(x % 16);
	if (x == 0)
	{
		write(1, &c, 1);
		return (1);	
	}
	else
		return (ft_print_x_)(x);
}

// void	ft_print_x(int x)
// {
// 	char	tab[9];
// 	char	c;
// 	int		i;
// 	int		digit;
// 	int		len;

// 	len = 0;
// 	i = 0;
// 	while (x > 0)
// 	{
// 		digit = x % 16;
// 		if (digit < 10)
// 			tab[i++] = (int) '0' + digit;
// 		else
// 			tab[i++] = (int) 'a' + (digit - 10);
// 		x = x / 16;
// 		len++;
// 	}
// 	while (i < (len / 2))
// 	{
// 		c = tab[i];
// 		tab[i] = tab[(len - 1) - i];
// 		tab[(len - 1) - i] = c;
// 		i++;
// 	}
// 	tab[len] = 0;
// 	ft_print_s(tab);
// }

