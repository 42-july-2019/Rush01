/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:52:32 by jvaquer           #+#    #+#             */
/*   Updated: 2019/07/14 23:39:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_empty(int *tab[SIZE + 2], int *x, int *y);
int		check_row(int *tab[SIZE + 2], int x, int nb);
int		check_col(int *tab[SIZE + 2], int y, int nb);
int		check_height_row_left(int *tab[SIZE + 2], int x);

int		check_height_row_right(int *tab[SIZE + 2], int x)
{
	int max;
	int count;
	int y;

	y = 5;
	max = 0;
	count = tab[x][y];
	y--;
	while (y > 0)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count--;
		}
		y--;
	}
	if (count == 0)
		return (1);
	return (0);
}

int		check_height_col_up(int *tab[SIZE + 2], int y)
{
	int max;
	int count;
	int x;

	x = 0;
	max = 0;
	count = tab[x][y];
	x++;
	while (x < 5)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count--;
		}
		x++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int		check_height_col_down(int *tab[SIZE + 2], int y)
{
	int max;
	int count;
	int x;

	x = 5;
	max = 0;
	count = tab[x][y];
	x--;
	while (x > 1)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count--;
		}
		x--;
	}
	if (count == 0)
		return (1);
	return (0);
}

int		conditions(int *tab[SIZE + 2], int x, int y, int nb)
{
	if (!check_row(tab, x, nb))
		return (0);
	if (!check_col(tab, y, nb))
		return (0);
	return (1);
}

int		solve_puzzle(int *tab[SIZE + 2])
{
	int x;
	int y;
	int nb;

	if (!find_empty(tab, &x, &y))
		return 1;
	nb = 1;
	while (nb <= 4)
	{
		if (conditions(tab, x, y, nb) == 1)
		{
			tab[x][y] = nb;
			if (solve_puzzle(tab))
			{
				return 1;
			}
			tab[x][y] = 0;
		}
		nb++;
	}
	return (0);
}
