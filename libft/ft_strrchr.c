/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:28:19 by ltromber          #+#    #+#             */
/*   Updated: 2021/12/13 15:27:49 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*        renvoie un pointeur sur la dernière occurrence du caractère C       */
/* --------------------------- dans la chaîne STR --------------------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ---------- renvoie un pointeur sur le caractère correspondant ou --------- */
/* ---------------- NULL si le caractère n'a pas été trouvé. ---------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*tmp;

	tmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (tmp);
}

/* int main(void)
{
	char chaine[] = "ltripouiel";

	char c = 'l';
	printf("VRAI : %s\n\n", strrchr(chaine, c));
	printf("MOI : %s\n", ft_strrchr(chaine, c));
} */