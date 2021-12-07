/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:28:19 by ltromber          #+#    #+#             */
/*   Updated: 2021/12/06 23:50:11 by ludovictrom      ###   ########.fr       */
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

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			str_size;

	i = 0;
	j = 0;
	str_size = ft_strlen(str);
	if (!str[i])
		return (NULL);
	i = str_size;
	if ((char) c == '\0')
		return ((char *) str + i);
	while (str_size--)
	{
		if (str[str_size] == (char) c)
			return ((char *) str + str_size);
	}
	return (NULL);
}

/* int main(void)
{
	char chaine[] = "123456789";

	char c = 'a';
	printf("VRAI : %s\n\n", strrchr(chaine, c));
	printf("MOI : %s\n", ft_strrchr(chaine, c));
} */