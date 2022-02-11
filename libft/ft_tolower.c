/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:20:23 by ltromber          #+#    #+#             */
/*   Updated: 2021/12/07 00:16:02 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*            convertit la lettre c en minuscule si c'est possible            */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ------------------------- la lettre convertie ou ------------------------- */
/* ---------------- C si la conversion n'était pas possible. ---------------- */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* 
int	main(void)
{
	int c;
	c = 'Z';

	printf("VRAI : %c\n", tolower(c));
	//ft_tolower(c);
	printf("MOI : %c\n", ft_tolower(c));
} */