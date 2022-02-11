/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:52:40 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:52:48 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*              Alloue (avec malloc(3)) et retourne une nouvelle              */
/* ----------- chaine, résultat de la concaténation de s1 et s2 ----------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* --------------------- la nouvelle chaine de cractères -------------------- */
/* ----------------------- NULL si l'allocation échoue ---------------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	s1_size;
	size_t	s2_size;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen((char *) s1);
	s2_size = ft_strlen((char *) s2);
	dest = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = 0;
	return (dest);
}

/* 
int main(void)
{
    const char s1[] = "my favorite animal is";
    const char s2[] = "coucou";
    printf("Dest: %s\n", ft_strjoin(s1, s2));
} */