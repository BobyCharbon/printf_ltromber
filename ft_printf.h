/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:06:02 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/21 15:30:59 by ludovictrom      ###   ########.fr       */
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
void	ft_print_c(char c);
void	ft_print_s(char *s);
void	ft_print_d(int d);
void	ft_print_u(unsigned u);
void	ft_print_x(int x);
void	ft_print_xmaj(int x);
void	ft_print_p(unsigned int p);
char	*ft_itoa_unsigned(unsigned int n);
char	hexcode(int digit);


#endif