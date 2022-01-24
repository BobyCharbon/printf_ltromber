/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:58:31 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/01/21 15:53:48 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

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

int	ft_print_by_value (char *s, va_list *arg_ptr)
{
	int tokensize;
	
	tokensize = 2;
	s++;
	if (*s == 'c')
		ft_print_c(va_arg(*arg_ptr, char));  
	if (*s == 's')
		ft_print_s(va_arg(*arg_ptr, char *));  
	if (*s == 'd' || *s == 'i')
		ft_print_d(va_arg(*arg_ptr, int));
	if (*s == 'u')
		ft_print_u(va_arg(*arg_ptr, unsigned));
	if (*s == 'x')
		ft_print_x(va_arg(*arg_ptr, int));
	if (*s == 'X')
		ft_print_xmaj(va_arg(*arg_ptr, int));
	if (*s == 'p')
		ft_print_p(va_arg(*arg_ptr, void *));
	if (*s == '%')
		ft_print_c(*s);
	return (tokensize);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int	tokensize;
	int max;
	max = 100;
	va_list arg_ptr;
	va_start(arg_ptr, max);                                                      
	i = 0;
	while (s[i])
	{
		if (s[i] != '%' && s[i] != '\\')
			write(1, s + i++, 1);
		if (s[i] == '%')
			i = i + ft_print_by_value(&s[i], &arg_ptr);
	}
	va_end(arg_ptr);
	return (0);
}

int main(void)
{
// 	char s[] = "|Bonjour|";
// 	char s1[] = "|Tout le monde|";
// 	char c = 'a';
// 	int d = 5555;
// 	int i = 5555;
// 	unsigned u = 5555;
	// int d = 545454;
	int x = 545454;
	// int u = 5454663543435;
// 	// printf ("%d\n", '\0');
// 	// ft_printf("MOI: %s %s %c %d %i \n", s, s1, c, d, i);
// 	// ft_printf("MOI: %s %s %c %d %i %u \n", s, s1, c, d, i, u);
// 	// printf("VRAI:%s %s %c %d %i %u \n", s, s1, c, d, i, u);
	ft_printf("MOI: %p %x \n", &x, &x);
	printf("VRAI:%p %x \n", &x, &x);
}

