/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:23:29 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/23 20:23:54 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_s(va_list *arg_ptr)
{
	int	count;

	char *s = va_arg(*arg_ptr, char *);
	count = 0;
	if (!s)
		s = ("(null)");
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}
