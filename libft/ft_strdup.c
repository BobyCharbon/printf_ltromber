/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:52:34 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:51:39 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*      renvoie un pointeur sur une nouvelle chaîne de caractères qui est     */
/* - dupliquée depuis STR. La mémoire occupée par cette nouvelle chaîne est - */
/* ----------------------- obtenue en appelant  malloc ---------------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ------------------ pointeur sur la chaîne dupliquée, ou ------------------ */
/* ---------------- NULL s'il n'y avait pas assez de mémoire. --------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_duplicate;
	int		str_len;

	str_len = ft_strlen(str);
	str_duplicate = malloc(ft_strlen (str) + 1);
	if (!str_duplicate)
		return (NULL);
	ft_strlcpy(str_duplicate, str, *(size_t *) str);
	return (str_duplicate);
}

/* 
int main(void)
{
    char str[] = "I malloc so I am.";
    printf("str_duplicate: %s\n", str_duplicate);
    ft_strdup(str);
} */