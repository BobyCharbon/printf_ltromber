/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_Xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:46:11 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/19 14:53:39 by ludovictrom      ###   ########.fr       */
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

void	ft_print_xmaj(int x)
{
	char	c;

	c = hexcode_xmaj(x % 16);
	if (x > 0)
		ft_print_xmaj(x / 16);
	else
		return ;
	write(1, &c, 1);
}