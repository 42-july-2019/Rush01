/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:36:02 by jvaquer           #+#    #+#             */
/*   Updated: 2019/07/14 23:39:07 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_empty(int *tab[SIZE + 2], int *x, int *y)
{
	*x = 1;
	while (*x < 5)
	{
		*y = 1;
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

int		check_row(int *tab[SIZE + 2], int x, int nb)
{
	int y;

	y = 1;
	while (y < 5)
	{
		if (tab[x][y] == nb)
		{
			return (0);
		}
		y++;
	}
	return (1);
}

int		check_col(int *tab[SIZE + 2], int y, int nb)
{
	int x;

	x = 1;
	while (x < 5)
	{
		if (tab[x][y] == nb)
			return (0);
		x++;
	}
	return (1);
}

int		check_height_row_left(int *tab[SIZE + 2], int x)
{
	int max;
	int count;
	int y;

	y = 0;
	max = 0;
	count = tab[x][y];
	y++;
	while (y < 5)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count--;
		}
		y++;
	}
	if (count == 0)
		return (1);
	return (0);
}
