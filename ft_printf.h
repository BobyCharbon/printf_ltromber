/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:12:14 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/25 16:26:45 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PERCENT '%'
# define FORMAT "cspdiuxX"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*ft_itoa_unsigned(unsigned int n);
char	hexcode(int digit);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_printf(const char*s, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_d(int d);
int		ft_print_u(unsigned int u);
int		ft_print_x(unsigned int x);
int		ft_print_xmaj(unsigned int x);
int		ft_print_p(unsigned long p);
#endif