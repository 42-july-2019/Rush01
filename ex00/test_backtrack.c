/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:52:32 by jvaquer           #+#    #+#             */
/*   Updated: 2019/07/14 17:39:24 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_empty(int tab[SIZE][SIZE], int *x, int *y)
{
	*x = 0;
	while (*x < 5)
	{
		*y = 0;
		while (*y < 5)
		{
			if (tab[*x][*y] == 0)
			{
				return (1);
			}
			*y += 1;
		}
		*x += 1;
	}
	return (0);
}

int		check_row(int tab[SIZE][SIZE], int x, int nb)
{
	int y;

	y = 0;
	while (y < 4)
	{
		if (tab[x][y] == nb)
		{
			return (0);
		}
		y++;
	}
	return (1);
}

int		check_col(int tab[SIZE][SIZE], int y, int nb)
{
	int x;

	x = 0;
	while (x < 4)
	{
		if (tab[x][y] == nb)
			return (0);
		x++;
	}
	return (1);
}

int		check_height_row(int tab[SIZE][SIZE], int x, int y)
{
	int max;
	int count;

	max = 0;
	count = 0;
	while (y < 4)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count++;
		}
		y++;
	}
	return (0);
}

int		check_height_col(int tab[SIZE][SIZE], int x, int y)
{
	int max;
	int count;

	max = 0;
	count = 0;
	while (x < 4)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count++;
		}
		x++;
	}
	return 0;
}

//TODO
int		conditions(int tab[SIZE][SIZE], int x, int y, int nb)
{
	if (!check_row(tab, x, nb))
		return 0;
	else if (!check_col(tab, y, nb))
		return 0;
	//else if (!check_height_row(tab, x, y))
	//	return 0;
	//else if (!check_height_col(tab, x, y))
	//	return 0;
	return 1;
}

int		solve_puzzle(int tab[SIZE][SIZE])
{
	int x;
	int y;
	int nb;

	if (!find_empty(tab, &x, &y))
		return 1;
	nb = 1;
	while (nb <= 4)
	{
		//printf("%d\n", nb);
		if (conditions(tab, x, y, nb) == 1)
		{
			tab[x][y] = nb;
			if (solve_puzzle(tab))
			{
				//printf("OK: %d,%d -> %d\n", x, y, nb);
				//break;
				return 1;
			}
			//printf("KO\n");
			//break;
			tab[x][y] = (0);
		}
		nb++;
	}
	return (0);
}
