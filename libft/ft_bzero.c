/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:06:34 by ltromber          #+#    #+#             */
/*   Updated: 2021/12/06 23:25:18 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*            La fonction bzero() met à 0 (octets contenant « \0 »)           */
/* -------------- les N premiers octets du bloc pointé par STR. ------------- */
/* -------------------------------------------------------------------------- */
/* --------------------------- VALEUR DE RETOUR: / -------------------------- */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = str;
	if (n <= 0)
		return (*str);
	while (j < (n - 1))
	{
		j = i;
		ptr[i] = 0;
		ptr[i] = ptr[j];
		i++;
	}
}

// int main (void)
// {
// 	char str[] = "Salut";
// 	size_t n = 2;
// 	ft_bzero(str, n);
// }