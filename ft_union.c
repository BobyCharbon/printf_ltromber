/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:17:41 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/05/15 13:35:14 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int used[255];
	int i = 0;
	int j = 0;

	if(argc == 3)
	{
		i = 0;
		while(i < 255)
			used[i++] = 0;
		i = 1;
		while(i < 3)
		{
			j = 0;
			while(argv[i][j] != 0)
			{
				if(used[(unsigned char)argv[i][j]] == '\0')
				{
					write(1, &argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 1;	
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}