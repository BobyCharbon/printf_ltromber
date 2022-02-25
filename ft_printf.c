/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltromber <ltromber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:58:31 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/25 16:19:39 by ludovictrom      ###   ########.fr       */
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

int	ft_format(char *s, va_list *arg_ptr)
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
			writesize += ft_format(&((char *) s)[i], &arg_ptr);
			i = i + 2;
		}
	}
	va_end(arg_ptr);
	return (writesize);
}

/* int	main(void)
{
	int	print;
	char	c = 'd';

	print = ft_printf("%d\n", c);
	print = ft_printf("%d\n", c);
	printf("VRAI: \\ %c \n", c);
	ft_printf("MOI: \\ %c \n", c);
	printf("|%d|\n", print);
	printf("|%d|\n", print);
} */

// TESTEUR GOTAGA:

/* int    main()
{
    int res;
    int bot;
    res = ft_printf("%x\n", 42);
    bot = printf("%x\n", 42);
    int res1;
    int bot1;
    res1 = ft_printf("%d\n", 56);
    bot1 = printf("%d\n", 56);
    int res2;
    int bot2;
    res2 = ft_printf("%s\n", "houlalala");
    bot2 = printf("%s\n", "houlalala");
    int res3;
    int bot3;
    res3 = ft_printf("%s\n", "32f2e234de");
    bot3 = printf("%s\n", "32f2e234de");
    //printf("resultat perso %d\nresultat ordi %d\n", res, bot);
    printf("resultat perso1 %d\nresultat ordi1 %d\n", res1, bot1);
    printf("resultat perso2 %d\nresultat ordi2 %d\n", res2, bot2);
    printf("resultat perso3 %d\nresultat ordi3 %d\n", res3, bot3);
    printf("resultat pnt %p\nresultat pnt %p\n", &res3, &bot3);
    return (0);
} */
