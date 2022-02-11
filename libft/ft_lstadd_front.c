/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltromber <ltromber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:51:02 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/02 11:14:02 by ltromber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* -------------------------------------------------------------------------- */
/*                 Ajoute l'élément 'new' au début de la liste                */
/* -------------------------------------------------------------------------- */
/* ----- alst = adresse du pointeur vers le premier élément de la liste ----- */
/* ----- new = adresse du pointeur vers l'élément à rajouter à la liste ----- */
/* -------------------------- VALEUR DE RETOUR : / -------------------------- */
/* -------------------------------------------------------------------------- */

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

// int main(void)
// {
//     void **alst = "Salut";
//     void *new = "T'es beau";
//     ft_lstadd_front(alst, new);
// }