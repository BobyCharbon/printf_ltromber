/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:52:24 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:41:20 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*        remplit les n premiers octets de la zone mémoire pointée par        */
/* ---------------------------- s avec l'octet c. --------------------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ---------------- renvoie un pointeur sur la zone mémoire S --------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (n--)
	{
		str[i] = c;
		i++;
	}
	return ((char *)str);
}

/* 
int main(void)
{
    char h[] = "A";
    char s[] = "A";

    size_t n;
    int c;
    
    n = 2;
    c = 'X';
    printf("VRAI : %s\n", memset(h, c, n));
    printf("Moi : %s\n", ft_memset(s, c, n));
}
 */