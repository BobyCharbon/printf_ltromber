/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:05 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 13:01:25 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:41:35 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/19 14:45:37 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_print_p_(unsigned long p)
{
	char	c;
	int count;
	count = 0;
	c = hexcode(p % 16);
	if (p > 0)
		count = 1 + ft_print_p_(p / 16);
	else
	{
		write(1, "0x", 2);
		// write(1, &c, 1);
		return (2);
	}
	write(1, &c, 1);
	return (count);
}

int	ft_print_p(unsigned long p)
{
	char	c;
	int count;
	count = 0;
	
	if (p == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
		return (ft_print_p_(p));
}