/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/03/01 19:24:31 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int	ft_format_i(va_list *arg_ptr)
{
	char	*token_itoa;
	int		count;
	int d;

	d = va_arg(*arg_ptr, int);
	token_itoa = ft_itoa(d);
	ft_format_s(&token_itoa);
	count = (ft_strlen(token_itoa));
	free(token_itoa);
	return (count);
}
