/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_exam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:47:52 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/12 16:01:21 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char**argv)
{
	/* argc = 3;
	argv[1] = "coucou";
	argv[2] = "coukcou"; */
	
	int used[255];
	int i;
	int j;
	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while(i > 0)
		{
			j = 0;
			while(argv[i][j] != '\0')
			{
				if(i == 2 && used[(unsigned char)argv[i][j]] == '\0')
					used[(unsigned char)argv[i][j]] = 1;
				else if(i == 1 && used[(unsigned char)argv[i][j]] == 1)
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
	return (0);	
}