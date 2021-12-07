/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltromber <ltromber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:44:11 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/02 15:48:50 by ltromber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* -------------------------------------------------------------------------- */
/*         Applique la fonction 'f' à chaque caractère de la chaine de        */
/* ---- cractère de la chaine de caractères passée en argument pour créer --- */
/* ------------- une nouvelle chaine de caractères (avec malloc) ------------ */
/* -------------- successives de 'f' résultant des applications ------------- */
/* -------------------------------------------------------------------------- */
/* ------------ *s = la chaine de caractères sur laquelle itérer ------------ */
/* ------------- *f = la fonction à appliquer à chaque caractère ------------ */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* ----- la chaine de caractères résultant des applications successives ----- */
/* ---------------------------------- de f. --------------------------------- */
/* ------------------ retourne NULL si l'allocation échoue ------------------ */
/* -------------------------------------------------------------------------- */

char	*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		i;
	int		len_of_s;

	if (!s)
		return (NULL);
	i = 0;
	len_of_s = ft_strlen((char *)s);
	str = malloc((len_of_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len_of_s)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
//         const char *s = "Salut";
//         char *f = "Mec";
//         ft_strmapi(s, f);
// }