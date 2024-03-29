/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:22:12 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 17:15:46 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 	up		-> 	i = 0, 			j ∈ [1, SIZE]
** 	down	-> 	i = SIZE + 1, 	j ∈ [SIZE, 1]
** 	left	-> 	i ∈ [1, SIZE], 	j = 0
** 	right	-> 	i ∈ [1, SIZE], 	j = SIZE + 1
*/

void	check_up_conditions(int *tab[SIZE + 2])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	while (j <= SIZE)
	{
		if (tab[i][j] == SIZE)
		{
			k = 1;
			while (k <= SIZE)
			{
				tab[i + k][j] = k;
				k++;
			}
		}
		else if (tab[i][j] == 1)
		{
			tab[i + 1][j] = SIZE;
		}
		j++;
	}
}

void	check_down_conditions(int *tab[SIZE + 2])
{
	int		i;
	int		j;
	int		k;

	i = SIZE + 1;
	j = 1;
	while (j <= SIZE)
	{
		if (tab[i][j] == SIZE)
		{
			k = 1;
			while (k <= SIZE)
			{
				tab[i - k][j] = k;
				k++;
			}
		}
		else if (tab[i][j] == 1)
		{
			tab[i - 1][j] = SIZE;
		}
		j++;
	}
}

void	check_left_conditions(int *tab[SIZE + 2])
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	while (i <= SIZE)
	{
		if (tab[i][j] == SIZE)
		{
			k = 1;
			while (k <= SIZE)
			{
				tab[i][j + k] = k;
				k++;
			}
		}
		else if (tab[i][j] == 1)
		{
			tab[i][j + 1] = SIZE;
		}
		i++;
	}
}

void	check_right_conditions(int *tab[SIZE + 2])
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = SIZE + 1;
	while (i <= SIZE)
	{
		if (tab[i][j] == SIZE)
		{
			k = 1;
			while (k <= SIZE)
			{
				tab[i][j - k] = k;
				k++;
			}
		}
		else if (tab[i][j] == 1)
		{
			tab[i][j - 1] = SIZE;
		}
		i++;
	}
}
