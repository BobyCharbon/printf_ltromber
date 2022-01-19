/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:05:21 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/19 13:36:09 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned u)
{
	int	d;
	if (u < 0)
	{
		// d = u >> 1;
		d = (u>>1) *2;
	}
	else
		d = (u>>1) * 2;
		// d = u;
	ft_print_d(d);
}