/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:58:31 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/24 14:03:15 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// caractères : cspdiuxX%
/* -------------------------------------------------------------------------- */
/*                                  ARGUMENTS:                                */
/* -------------------------------------------------------------------------- */
/* ----------------------------------- \b ----------------------------------- */
/* --------------------- Write a <backspace> character. --------------------- */
/* ----------------------------------- \f ----------------------------------- */
/* --------------------- Write a <form-feed> character. --------------------- */
/* ----------------------------------- \n ----------------------------------- */
/* ---------------------- Write a <new-line> character. --------------------- */
/* ----------------------------------- \r ----------------------------------- */
/* ------------------ Write a <carriage return> character. ------------------ */
/* ----------------------------------- \t ----------------------------------- */
/* ------------------------ Write a <tab> character. ------------------------ */
/* ----------------------------------- \v ----------------------------------- */
/* -------------------- Write a <vertical tab> character. ------------------- */
/* ----------------------------------- \´ ----------------------------------- */
/* -------------------- Write a <single quote> character. ------------------- */
/* ----------------------------------- \\ ----------------------------------- */
/* ---------------------- Write a backslash character. ---------------------- */
/* ---------------------------------- \num ---------------------------------- */
/* -- Write a byte whose value is the 1-, 2-, or 3-digit octal number num. -- */
/* - Multibyte characters can be constructed using multiple \num sequences. - */
/* -------------------------------------------------------------------------- */
/*                              VALEUR DE RETOUR:                             */
/* -------------------------------------------------------------------------- */
/* ------- Si elles réussissent, ces fonctions renvoient le nombre de ------- */
/* ------- caractères imprimés, sans compter l'octet nul « \0 » final. ------ */
/* ----- Les fonctions snprintf() et vsnprintf() n'écrivent pas plus de ----- */
/* -- size octets (y compris le « \0 » final). Si la sortie a été tronquée -- */
/* -- à cause de la limite, la valeur de retour est le nombre de caractères - */
/* ------ (sans le « \0 » final) qui auraient été écrits dans la chaîne ----- */
/* --- s'il y avait eu suffisamment de place. Ainsi, une valeur de retour --- */
/* ----------- size ou plus signifie que la sortie a été tronquée. ---------- */
/* ----------------- (Voir aussi la section NOTES plus bas). ---------------- */
/* ----- Si une erreur de sortie s'est produite, une valeur négative est ---- */
/* -------------------------------- renvoyée. ------------------------------- */

/* -------------------------------------------------------------------------- */
/*                        fonctions externes autorisées:                      */
/* --------- malloc, free, write, va_start, va_arg, va_copy, va_end --------- */
/* -------------------------------------------------------------------------- */

/* int	ft_format(char *s, va_list *arg_ptr)
{
	int	tokensize;

	tokensize = 0;
	s++;
	if (*s == 'c')
		tokensize = ft_format_c((va_arg(*arg_ptr, int)));
	if (*s == 's')
		tokensize = ft_format_s(va_arg(*arg_ptr, char *));
	if (*s == 'd' || *s == 'i')
		tokensize = ft_format_d(va_arg(*arg_ptr, int));
	if (*s == 'u')
		tokensize = ft_format_u(va_arg(*arg_ptr, unsigned));
	if (*s == 'x')
		tokensize = ft_format_x(va_arg(*arg_ptr, int));
	if (*s == 'X')
		tokensize = ft_format_xmaj(va_arg(*arg_ptr, int));
	if (*s == 'p')
		tokensize = ft_format_p((unsigned long)(va_arg(*arg_ptr, void *)));
	if (*s == '%')
		tokensize = ft_format_c(*s);
	return (tokensize);
} */

int	ft_format(const char *c, va_list *arg_ptr)
{
	static const t_format_function	format_functions[] = {ft_format_c,
		ft_format_s, ft_format_p,
		ft_format_d, ft_format_i,
		ft_format_u, ft_format_x,
		ft_format_xmaj};
	int								i;

	i = 0;
	while (FORMAT[i] != '\0')
	{
		if (FORMAT[i] == c)
			return (format_functions[i]);
		i++;
	}
	return (write(1, &c, sizeof(c)));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		writesize;
	va_list	arg_ptr;

	i = 0;
	writesize = 0;
	va_start(arg_ptr, s);
	while (s[i] != '\0')
	{
		if (s[i] != PERCENT)
		{
			writesize++;
			write(1, s + i++, 1);
		}
		if (s[i] == PERCENT)
		{
			i++;
			writesize += ft_format(&((char *) s)[i], &arg_ptr);
			// i = i + 2;
		}
	}
	va_end(arg_ptr);
	return (writesize);
}

int	main(void)
{
	int	print;
	char	c = 'c';

	print = ft_printf("%d\n", c);
	print = ft_printf("%d\n", c);
	printf("VRAI: \\ %c \n", c);
	ft_printf("MOI: \\ %c \n", c);
	printf("|%d|\n", print);
	printf("|%d|\n", print);
	// ft_printf("|%c %c %c|\n", '0');
}
