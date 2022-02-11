/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:50:23 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:27:33 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*       calloc() alloue la mémoire nécessaire pour un tableau de COUNT       */
/* ------- éléments de taille size octets, et renvoie un pointeur vers ------ */
/* ------- la mémoire allouée. Cette zone est remplie avec des zéros. ------- */
/* ---------- Si nmemb ou size vaut 0, calloc() renvoie soit NULL, ---------- */
/* ----- soit un pointeur unique qui pourra être passé ultérieurement à ----- */
/* --------------------------- free() avec succès. -------------------------- */
/* -------------------------------------------------------------------------- */
/* ----------- VALEUR DE RETOUR: pointeur sur la mémoire allouée. ----------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*ptr;
	int	len;

	len = count * size;
	ptr = malloc(len);
	if (ptr == NULL)
		return (ptr);
	ft_memset(ptr, 0, len);
	return (ptr);
}

/* 
int main(void)
{
    size_t count = 5;
    size_t size = 2;

    int *ptr;

    ft_calloc(count, size);
} */
