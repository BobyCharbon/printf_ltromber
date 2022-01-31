/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:23:29 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 12:49:15 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int count;
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