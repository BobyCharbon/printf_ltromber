/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltromber <ltromber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:19:56 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/09 15:41:51 by ltromber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* -------------------------------------------------------------------------- */
/*              Applique la fonction f à chaque caractère de la             */
/* ----------- chaîne de caractères transmise comme argument, et ---------- */
/* ----------- en passant son index comme premier argument. Chaque ---------- */
/* ----------- caractère est transmis par adresse à f pour être ---------- */
/* ------------------------ modifié si nécessaire. ------------------------ */
/* -------------------------------------------------------------------------- */
/* ------------ S = la chaine de caractères sur laquelle itérer ------------ */
/* ------------- F = la fonction à appliquer à chaque caractère ------------ */
/* -------------------------------------------------------------------------- */
/* --------------------------- VALEUR DE RETOUR: / -------------------------- */
/* -------------------------------------------------------------------------- */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	strlen;

	if (!s)
		return ;
	i = 0;
	strlen = ft_strlen(s);
	while (i < strlen)
	{
		f(i, &s[i]);
		i++;
	}	
}
