/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:54:13 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/07 00:00:02 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*           La fonction strcmp() compare les deux chaînes s1 et s2.          */
/* ------- Elle renvoie un entier négatif, nul, ou positif, si s1 est ------- */
/* ---------- respectivement inférieure, égale ou supérieure à s2. ---------- */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*       La fonction strncmp() est identique sauf qu'elle ne compare que      */
/* ------------ les n (au plus) premiers caractères de s1 et s2. ------------ */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ----------- un entier inférieur, égal ou supérieur à zéro si s1 ---------- */
/* -------- (ou ses n premiers octets) est respectivement inférieure, ------- */
/* ------------------------ égale ou supérieure à s2. ----------------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!*str1 && !*str2) || n == 0)
		return (0);
	while ((str1[i] == str2[i]) && i < n - 1 && str1[i] && str2[i])
		i++;
	if (str1[i] != str2[i])
		return (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]);
	return (0);
}

/* 
int main(void)
{
    char str1[] = "atoms\0\0\0\0";
    char str2[] = "atoms\0abc";
    size_t n = 7;
    
    printf("VRAI: %d\n", strncmp(str1, str2, n));
    printf("Moi: %d\n", ft_strncmp(str1, str2, n));
}
 */