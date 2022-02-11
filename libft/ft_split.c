/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:52:23 by ludovictrom       #+#    #+#             */
/*   Updated: 2021/12/06 23:47:32 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* -------------------------------------------------------------------------- */
/*            Fonction allouant avec Malloc et retourne un tableau            */
/* ------------- de chaine de caractères obtenue en séparant 'S' ------------ */
/* ------------------------ à l'aide du caractère 'C' ----------------------- */
/* -------------------------------------------------------------------------- */
/* ------------------ le tableau doit se terminer par NULL ------------------ */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* -------------- le tableau de nouvelles chaines de caracères -------------- */
/* ------------------------- résultant du découpage. ------------------------ */
/* ----------------------- NULL si l'allocation échoue ---------------------- */
/* -------------------------------------------------------------------------- */

static int	ft_wordlen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_char(char const *s, char c)
{
	_Bool	is_in_word;
	int		i;
	int		count_char;

	i = -1;
	is_in_word = false;
	count_char = 0;
	if (c == '\0' && s[0] == '\0')
		return (0);
	else if (c == '\0')
		return (1);
	while (s[++i])
	{
		if (s[i] == c)
			is_in_word = false;
		else
		{
			if (!is_in_word)
			{
				is_in_word = true;
				count_char++;
			}
		}
	}
	return (count_char);
}

static char	**ft_free(char **res, int words)
{
	int		i;

	i = 0;
	if (!res)
		return (NULL);
	while (i < words)
	{
		if (res[i])
			free(res[i++]);
	}
	free(res);
	return (NULL);
}

static char	**ft_fill_res(char const *s, char c, char ***res, int count_char)
{
	int		i;
	int		j;
	_Bool	is_in_word;

	i = -1;
	j = 0;
	is_in_word = false;
	while (j < count_char)
	{
		if (s[++i] == c)
		{
			is_in_word = false;
			continue ;
		}
		if (!is_in_word)
		{
			is_in_word = true;
			(*res)[j] = malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1));
			if (!(*res)[j])
				return (ft_free(*res, (j - 1)));
			ft_strlcpy((*res)[j++], &s[i], (ft_wordlen(&s[i], c) + 1));
		}
	}
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	int		count_char;
	char	**res;

	if (!s)
		return (NULL);
	count_char = ft_count_char(s, c);
	res = malloc(sizeof(char *) * (count_char + 1));
	if (!res)
		return (NULL);
	res = ft_fill_res(s, c, &res, count_char);
	res[count_char] = NULL;
	return (res);
}

// int main(void)
// {
//     char s[] = "Salut mec";
//     char c = ' ';
//     printf("RESULTAT : |%s|\n", ft_split(s, c));
// }