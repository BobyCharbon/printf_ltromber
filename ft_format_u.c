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

int	ft_format_u(unsigned int u)
{
	char	*token;
	int		count;

	token = ft_itoa_unsigned(u);
	count = ft_strlen(token);
	ft_format_s(token);
	free(token);
	return (count);
}
