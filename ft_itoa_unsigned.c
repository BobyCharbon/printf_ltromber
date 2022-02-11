/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:59:25 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/02/11 15:56:16 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */
/*              Alloue (avec malloc(3)) et retourne une chaine de             */
/* --------- caractères représentant l’integer reçu en argument. --------- */
/* -------------------------------------------------------------------------- */
/* -------------- Les nombres négatifs doivent être gérés. -------------- */
/* -------------------------------------------------------------------------- */
/* ---------------------------- VALEUR DE RETOUR: --------------------------- */
/* --------------- la chaine de caractères représentant l'int --------------- */
/* ---------------------- NULL si l’allocation échoue. --------------------- */
/* -------------------------------------------------------------------------- */

static int	ft_nbrlen_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n / -10;
		i = 2;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*s;
	int		number_of_char;
	int		i;

	number_of_char = ft_nbrlen_unsigned(n);
	s = malloc(sizeof(char) * (number_of_char + 1));
	if (s == NULL)
		return (NULL);
	i = number_of_char - 1;
	s[number_of_char] = '\0';
	if (n == 0)
		s[i] = n % 10 + 48;
	if (n < 0)
	{
		s[0] = '-';
		s[i--] = -(n % 10) + 48;
		n = n / -10;
	}
	while (n > 0)
	{
		s[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
/* 
int main(void)
{
	unsigned int n = 2147483647;
	printf("RESULTAT: |%s|\n", (ft_itoa_unsigned(n)));
} */