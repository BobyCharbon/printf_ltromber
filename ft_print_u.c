/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:05:21 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 13:15:44 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned u)
{
	int	d;
	int count;
	char *token;
	token = ft_itoa_unsigned(u);
	count = strlen(token);
	ft_print_s(token);
	free(token);
	return (count);
}