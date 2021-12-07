/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:51:43 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:40:17 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*    copie n octets depuis la zone mémoire src vers la zone mémoire dest.    */
/* ---- Les deux zones peuvent se chevaucher : la copie se passe comme si --- */
/* ---- les octets de src étaient d'abord copiés dans une zone temporaire --- */
/* --- qui ne chevauche ni src ni dest, et les octets sont ensuite copiés --- */
/* -------------------- de la zone temporaire vers dest. -------------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ---------------------------- pointeur sur DEST --------------------------- */
/* -------------------------------------------------------------------------- */


#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	i = (int) n - 1;
	while (i >= 0)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i--;
		if (dest + i == 0)
			return (dest);
	}
	return (dest);
}

/* 
int main(void)
{
	char dest[] = "Coucou toi";
	char src[] = "T bo";

	size_t n = 10;
	printf("VRAI: %s\n", memmove(dest, src, n));
	printf("Moi: %s\n", ft_memmove(dest, src, n));
} */