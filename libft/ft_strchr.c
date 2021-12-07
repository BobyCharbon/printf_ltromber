/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:37:40 by ltromber          #+#    #+#             */
/*   Updated: 2021/12/06 23:48:55 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*        renvoie un pointeur sur la première occurrence du caractère C       */
/* --------------------------- dans la chaîne STR. -------------------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ---------- renvoie un pointeur sur le caractère correspondant ou --------- */
/* ----------------- NULL si le caractère n'a pas été trouvé ---------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strchr(const char	*str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
	{
		return ((char *) str + i);
	}
	return (NULL);
}

/* 
int	main(void)
{
	char	chaine[] = "Ah ouais gros tema ta taille du raph";
	//char	dest[50];

	int c = '\0';
	//ft_strchr(chaine, c);
	printf("VRAI : %s\n\n",strchr(chaine, c));
	//printf("Source : %s\n", chaine);
	//printf("A Rechercher : %c\n", c);
	printf("MOI : %s\n", ft_strchr(chaine, c));
} */