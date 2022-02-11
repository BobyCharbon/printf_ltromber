/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:02:45 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/07 00:08:27 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*                 Alloue avec malloc et retourne une copie de                */
/* ------------ la chaine ’s1’, sans les caractères spécifiés ------------ */
/* ------------ dans ’set’ au début et à la fin de la chaine de ----------- */
/* ------------------------------ caractères. ------------------------------ */
/* -------------------------------------------------------------------------- */
/* ----------------- S1 = la chaine de caractères à trimmer ---------------- */
/* ----------- SET = le set de référence de caractères à trimmer ----------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* -------------------- la chaine de caractères trimmée -------------------- */
/* ----------------------- NULL si l'allocation échoue ---------------------- */
/* -------------------------------------------------------------------------- */

#include "libft.h"

static	size_t	ft_string_end(char *s1, char *set, int i)
{
	size_t	s1_size;
	int		k;

	s1_size = ft_strlen(s1);
	k = 0;
	while (s1[i])
	{
		while (s1[s1_size] != set[k])
		{
			if (!set[k])
				return (s1_size + 1);
			k++;
		}
		k = 0;
		s1_size--;
	}
	return (s1_size);
}

static	size_t	ft_string_start(char *s1, char *set, int k)
{
	size_t	i;

	i = 0;
	if (!set[k])
		return (0);
	while (s1[i])
	{
		while (s1[i] != set[k])
		{
			k++;
			if (!set[k])
				return (i);
		}
		k = 0;
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*tmp;
	size_t	j;
	size_t	k;
	int		s1_size_end;
	int		s1_size_start;

	j = 0;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	if ((char *) set == NULL)
		return ((char *) s1);
	s1_size_start = ft_string_start((char *) s1, (char *) set, k);
	s1_size_end = ft_string_end((char *) s1, (char *) set, s1_size_start);
	tmp = malloc(s1_size_end - s1_size_start + 1 * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (s1_size_start < s1_size_end)
	{
		tmp[j] = ((char *) s1)[s1_size_start];
		j++;
		s1_size_start++;
	}
	tmp[j] = 0;
	return ((char *) tmp);
}

/* 
int main(void)
{
    const char s1[] = "xxxxxxxxx";
    const char set[] = "";
    printf("RESULTAT: |%s|\n", ft_strtrim(s1, set));
} */