/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:52:53 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:56:51 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*      copie jusqu'à la taille - 1 caractères de la chaîne de caractères     */
/* --- terminée par NULL SRC vers DEST, en terminant par NULL le résultat. -- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* --------------------------- la longueur de SRC --------------------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	int		src_size;

	i = 0;
	src_size = ft_strlen((char *) src);
	if (dest_size <= 0)
		return (src_size);
	while (i < (dest_size - 1) && i < (size_t) src_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_size);
}

/* 
int main(void)
{
    char src[] = "YYYY";
    char dest[] = "";
    
    size_t dest_size = 2;

    printf("MOI : %lu\n", ft_strlcpy(dest, src, dest_size));
    printf("VRAI : %lu\n", strlcpy(dest, src, dest_size));
} */