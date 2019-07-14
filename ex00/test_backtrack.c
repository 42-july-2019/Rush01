/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:52:32 by jvaquer           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:27 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_empty(int tab[SIZE][SIZE], int *x, int *y)
{
	*x = 1;

	while (x < 5)
	{
		*y = 1;
		while (y < 5)
		{
			if (tab[x][y] == 0)
				return 1;
			y++;
		}
		x++;
	}
	return 0;
}

int		check_row(int tab[SIZE][SIZE], int x, int nb)
{
	int y;

	y = 0;
	while (x <= 4)
	{
		if (tab[x][y] == nb)
			return 0;
		y++;
	}
	return 1;
}

int		check_col(int tab[SIZE][SIZE], int y, int nb)
{
	int x;

	x = 0;
	while (y <= 4)
	{
		if (tab[x][y] == nb)
			return 0;
		y++;
	}
	return 1;
}

//TODO
int		check_height(int tab[SIZE][SIZE], int x, int y)
{
	
}
//TODO
int		conditions(int tab[SIZE][SIZE], int x, int y, int nb)
{
	
}

int		solve_puzzle(int tab[SIZE][SIZE])
{
	int x;
	int y;
	int nb;

	if (!find_empty(tab, &x, &y))
		return 1;
	while (nb <= 4)
	{
		if (conditions(tab, x, y, nb))
		{
			tab[x][y] = nb;
			if (solve_puzzle(tab))
				return 1;
			tab[x][y] = 0;
		}
		nb++;
	}
	return 0;
}
