
/* -------------------------------------------------------------------------- */
/*              Écrire un programme qui prend en paramètres deux              */
/* ---------------------- chaînes de caractères et qui ---------------------- */
/* ------ affiche sans doublon les caractères communs aux deux chaînes. ----- */
/* - L'affichage se fera dans l'ordre d'apparition dans la premiere chaîne. - */
/* -------------------------------------------------------------------------- */
/* ----------------- L'affichage doit être suivi d'un '\n'. ----------------- */
/* -------------------------------------------------------------------------- */
/* --------- Si le nombre de paramètres transmis est différent de 2, -------- */
/* -------------------------- le programme affiche -------------------------- */
/* ---------------------------------- '\n'. --------------------------------- */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int ft_inter (char *str1, char *str2);
int ft_strlen(char *str);
bool ft_check_occurence(char *stroccurence, char char_of_str1);

bool ft_check_occurence(char *stroccurence, char char_of_str1)
{
	int j = 0;

	while (stroccurence[j] != '\0')
	{
		if (stroccurence[j] == char_of_str1)
			return (true);
		else
			j++;
	}
	return (false);
}

int ft_inter (char *str1, char *str2)
{
	int j = 0;
	// int strlen1 = ft_strlen(argv1);
	// int strlen2 = ft_strlen(argv2);

	int len1 = 0;
	int len2 = 0;

	char *stroccurence;
	stroccurence = malloc(sizeof(ft_strlen(str1)));
	if (stroccurence == NULL)
		return (0);

	while (str1[len1] != '\0')
	{
		if (str1[len1] == str2[len2++])
		{
			if (ft_check_occurence(stroccurence, str1[len1]) == false)
			{
				stroccurence[j++] = str1[len1];
				len1++;
				len2 = 0;
				// printf("STR OCCURENCE : %s\n", stroccurence);
			}
		}
		if (str2[len2] == '\0')
		{
			len1++;
			len2 = 0;
		}
	}
	if (stroccurence[0] == '\0')
		write (1, "\n", 1);
	else
	{
		write(1, stroccurence, sizeof(stroccurence));
		write (1, "\n", 1);
	}
				
	// printf("STR OCCURENCE (final): %s\n", stroccurence);
	// printf("OCCURENCE : %d\n", occurence);
	return (0);
}

int main(void)
{
	char *str1 = "oucouo";
	char *str2 = "cavaoo";
	ft_inter(str1, str2);
}

int ft_strlen(char *str)
{
	int lenstr = 0;

	while (str[lenstr] != '\0')
		lenstr++;
	return (lenstr);
}
