
// /* -------------------------------------------------------------------------- */
// /*              Écrire un programme qui prend en paramètres deux              */
// /* ---------------------- chaînes de caractères et qui ---------------------- */
// /* ------ affiche sans doublon les caractères communs aux deux chaînes. ----- */
// /* - L'affichage se fera dans l'ordre d'apparition dans la premiere chaîne. - */
// /* -------------------------------------------------------------------------- */
// /* ----------------- L'affichage doit être suivi d'un '\n'. ----------------- */
// /* -------------------------------------------------------------------------- */
// /* --------- Si le nombre de paramètres transmis est différent de 2, -------- */
// /* -------------------------- le programme affiche -------------------------- */
// /* ---------------------------------- '\n'. --------------------------------- */
// /* -------------------------------------------------------------------------- */

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdbool.h>


// int main(int argc, char **argv)
// {
// 	int tab[255];
// 	int i = 0;
// 	int j = 0;
// 	argc = 3;
// 	if (argc == 3)
// 	{
// 		while (tab[i++] != '\0')
// 			tab[i] = 0;
// 		i = 2;
// 		while (argv[i][j] != '\0')
// 		{
// 			if (i == 2 && tab[argv[i][j] == '\0'])
// 				tab[argv[i][j]] = 1;
// 			else if (i == 1 && tab[argv[i][j]] == 1)
// 			{
// 				write (1, &argv[i][j], 1);
// 				tab[argv[i][j]] = 2;
// 			}
// 			j++;
// 		}
// 		i--;
// 	}
// 	write (1, "\n", 1);
// 	return (0);
// }
