/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:58:31 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/14 11:06:41 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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

char	ft_pourcent_c (char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_detect_pourcent (char s)
{
	if (s == 'c')
		return (0);
	else if (s == 'd' || s == 'i')
	
	if (s == 's')
}

int	ft_printf(const char *s, ...)
{
	int	i;
	char	*str;

	str = (char*) s;
	i = 0;
	while (s[i] && s[i] != '%')
	{
		write(1, s + i, 1);
		i++;
	}
	if (s[i] == '%')
	{
		ft_detect_pourcent((*(char *)s + i) + 1);
	}
	return (0);
}

int main(void)
{
	char s[] = "Salut %c";
	ft_printf(s);
}