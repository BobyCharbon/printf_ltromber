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

typedef int(*t_format_function)(va_list *arg_ptr);


char	*ft_itoa_unsigned(unsigned int n);
char	hexcode(int digit);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int	ft_format_c(va_list *arg_ptr);
int	ft_format_s(va_list *arg_ptr);
int	ft_format_d(va_list *arg_ptr);
int	ft_format_i(va_list *arg_ptr);
int	ft_format_u(va_list *arg_ptr);
int	ft_format_x(va_list *arg_ptr);
int	ft_format_xmaj(va_list *arg_ptr);
int	ft_format_p(va_list *arg_ptr);
int		ft_formatf(const char*s, ...);

#endif
