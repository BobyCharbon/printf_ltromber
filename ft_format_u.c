/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:05:21 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/23 19:48:59 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_u(va_list *arg_ptr)
{
	char	*token;
	int		count;

	unsigned long u = va_arg(*arg_ptr, unsigned long);
	token = ft_itoa_unsigned(u);
	count = ft_strlen(token);
	write(1, token, count);
	free(token);
	return (count);
}
