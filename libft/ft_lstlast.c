/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:09:08 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/07 19:38:21 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if(!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int main(void)
// {
// 	void *debut_liste;
// 	ft_lstlast(debut_liste);
// }