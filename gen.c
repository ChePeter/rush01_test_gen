/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrueben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:57:59 by lrueben           #+#    #+#             */
/*   Updated: 2019/08/11 12:17:53 by lrueben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int     check_p(int n, int x, int y, int t[9][9]);
void    print_t(int t[9][9]);

int		main(int argc, char *argv[])
{
	int n;
	int t[9][9];
	int i;
	int j;
	int k;
	int kk;
	int nn;
	int p[81][3];
	
	if (argc != 2)
	{
		write(1,"Error\n",7);
		return (0);
	}
	srand(time(NULL));
	n = atoi(argv[1]);

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			t[i][j] = 0;
			p[i * 9 + j][0] = 0;
			p[i * 9 + j][1] = 0;
			p[i * 9 + j][2] = 0;
			j++;
		}
	i++;
	}
	nn = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (rand()%100 > 100 - n)
			{
//				printf(" check nn %d x %d y %d\n",nn,i,j);
				kk = 0;
				k = rand() % 9 + 1;
				while(check_p(k, i, j, t) != 0 && kk++ < 9)
				{
					k = (k + 1) % 9 + 1;
				}
				if (kk == 9)
				{
//					printf(" del nn %d  x %d y %d\n",nn,i,j);
					nn--;
					t[p[nn][1]][p[nn][2]] = 0;
					i = p[nn][1];
					j = p[nn][2];
				}
				else
				{
//					printf(" add nn %d k %d  x %d y %d\n",nn,k,i,j);
					nn++;
					p[nn][0] = k;
					p[nn][1] = i;
					p[nn][2] = j;
					t[i][j] = k;
				}
			}
			j++;
		}
	i++;
	}
	print_t(t);
	return (0);
}


