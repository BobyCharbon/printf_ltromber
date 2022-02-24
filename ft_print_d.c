/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/24 14:09:32 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int	ft_print_d(int d)
{
	char	*token_itoa;
	int		count;

	token_itoa = ft_itoa(d);
	ft_print_s(token_itoa);
	count = (ft_strlen(token_itoa));
	free(token_itoa);
	return (count);
}
