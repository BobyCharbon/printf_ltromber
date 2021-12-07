/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:52:46 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:55:03 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*        copie et concatène des chaînes de caractères respectivement.        */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ----------- la longueur initiale de DEST + la longueur de SRC. ----------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	j = dest_len;
	if (!dest || !src || len <= 0 || len < dest_len)
		return (src_len + len);
	while (j < (len - 1) && i < (src_len))
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (src_len + dest_len);
}

/* 
int main(void)
{
    char dest [] = "XXXXXXXXXX";
    char src [] = "YYYYY";

    char dest_test [] = "XXXXXXXXXX";
    char src_test [] = "YYYYY";

    size_t len = 1;

    printf("Moi: %zu\n", ft_strlcat(dest, src, len));
    printf("VRAI: %zu\n", strlcat(dest_test, src_test, len));
    printf("\ndest_test : %s\n", dest_test);
    printf("dest      : %s\n", dest);
} */