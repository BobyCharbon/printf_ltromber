/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:42:39 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/16 19:58:00 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i, j = 0;
	int used[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while(argv[i][j])
			{
				if (i == 1 && used[(unsigned char)argv[i][j]] == '\0')
				{
					used[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);	
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}