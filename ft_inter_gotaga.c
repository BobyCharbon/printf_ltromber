#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_inter_gotaga(int argc, char **argv)
{
	int	used[255];
	int	i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (i == 2 && !used[(unsigned char)argv[i][j]])
					used[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	// printf("STRING GOTAGA: %s\n", argv[3]);
	return (0);
}

/* int main(void)
{
	char *str1 = "coucou";
	char *str2 = "cava";
	ft_inter_gotaga(str1, str2);
} */