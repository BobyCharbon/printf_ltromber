/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:21:20 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/23 19:48:20 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_c(va_list *arg_ptr)
{
	const char c = va_arg(*arg_ptr, int);
	write(1, &c, 1);
	return (1);
}
