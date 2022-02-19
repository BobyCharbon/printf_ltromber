/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:58:31 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/19 16:01:20 by ludovictrom      ###   ########.fr       */
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

int	ft_print_by_value(char *s, va_list *arg_ptr)
{
	int	tokensize;

	tokensize = 0;
	s++;
	if (*s == 'c')
		tokensize = ft_print_c((va_arg(*arg_ptr, int)));
	if (*s == 's')
		tokensize = ft_print_s(va_arg(*arg_ptr, char *));
	if (*s == 'd' || *s == 'i')
		tokensize = ft_print_d(va_arg(*arg_ptr, int));
	if (*s == 'u')
		tokensize = ft_print_u(va_arg(*arg_ptr, unsigned));
	if (*s == 'x')
		tokensize = ft_print_x(va_arg(*arg_ptr, int));
	if (*s == 'X')
		tokensize = ft_print_xmaj(va_arg(*arg_ptr, int));
	if (*s == 'p')
		tokensize = ft_print_p((unsigned long)(va_arg(*arg_ptr, void *)));
	if (*s == '%')
		tokensize = ft_print_c(*s);
	return (tokensize);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		writesize;
	int		max;
	va_list	arg_ptr;

	max = 100;
	i = 0;
	writesize = 0;
	va_start(arg_ptr, s);
	while (s[i])
	{
		if (s[i] != '%' && s[i] != '\\')
		{
			writesize++;
			write(1, s + i++, 1);
		}
		if (s[i] == '%')
		{
			writesize += ft_print_by_value(&((char *) s)[i], &arg_ptr);
			i = i + 2;
		}
	}
	va_end(arg_ptr);
	return (writesize);
}

int	main(void)
{
	int	print;
	char	c = 'd';

	print = ft_printf("%d\n", c);
	print = ft_printf("%d\n", c);
	printf("VRAI:  %c \n", c);
	ft_printf("MOI:  %c \n", c);
	printf("|%d|\n", print);
	printf("|%d|\n", print);
	// ft_printf("|%c %c %c|\n", '0');
}
