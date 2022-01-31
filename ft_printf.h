/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:06:02 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/31 13:24:21 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>

# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char*s, ...);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_d(int d);
int	ft_print_u(unsigned u);
int	ft_print_x(unsigned int x);
int	ft_print_xmaj(unsigned int x);
int	ft_print_p(unsigned long p);
char	*ft_itoa_unsigned(unsigned int n);
char	hexcode(int digit);


#endif