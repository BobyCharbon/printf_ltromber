/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/23 19:48:27 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int	ft_format_d(va_list *arg_ptr)
{
	char	*token_itoa;
	int		count;
	int		d;

	d = va_arg(*arg_ptr, int);
	token_itoa = ft_itoa(d);
	ft_format_s(token_itoa);
	count = (ft_strlen(token_itoa));
	free(token_itoa);
	return (count);
}
