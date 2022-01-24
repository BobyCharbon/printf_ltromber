/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:05:21 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/21 15:09:27 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned u)
{
	int	d;

	// d = (u>>1);
	// ft_print_d(d);
	ft_print_s(ft_itoa_unsigned(u));
}