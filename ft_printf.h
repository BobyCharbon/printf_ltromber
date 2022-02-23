/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:06:02 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/23 19:45:54 by ludovictrom      ###   ########.fr       */
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

typedef int(*t_format_function)(t_printf *);

char	*ft_itoa_unsigned(unsigned int n);
char	hexcode(int digit);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_formatf(const char*s, ...);
int		ft_format_c(char c);
int		ft_format_s(char *s);
int		ft_format_d(int d);
int		ft_format_u(unsigned int u);
int		ft_format_x(unsigned int x);
int		ft_format_xmaj(unsigned int x);
int		ft_format_p(unsigned long p);

#endif