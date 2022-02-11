/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:00:13 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:38:33 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*          compare les n premiers octets des zones mémoire s1 et s2.         */
/* ------ Elle renvoie un entier inférieur, égal, ou supérieur à zéro, ------ */
/* ------ si s1 est respectivement inférieure, égale ou supérieur à s2. ----- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* -- renvoie un entier négatif, nul ou positif si les n premiers octets de - */
/* ------- s1 sont respectivement inférieurs, égaux ou supérieurs aux ------- */
/* ------------------------ n premiers octets de s2. ------------------------ */
/* -------------------------------------------------------------------------- */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str;
	const unsigned char	*str2;
	int					i;
	int					j;

	str = s1;
	str2 = s2;
	i = 0;
	j = 0;
	while (n--)
	{
		if (str[i] != str2[i])
		{
			j = str[i] - str2[i];
			return (j);
		}
		if (str[i] == str2[i])
		{
			i++;
		}
	}
	return (0);
}

/* 
int main(void)
{
    const char s1[] = "\xff\xaa\xde\xffMACOSX\xff";
    const char s2[] = "\xff\xaa\xde\x02";
    
    size_t n;
    n = 30;

    printf("VRAI : %d\n\n", memcmp(s1, s2, n));
    printf("MOI: : %d\n", ft_memcmp(s1, s2, n));
} */