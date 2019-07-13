/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:53 by jvaquer           #+#    #+#             */
/*   Updated: 2019/07/13 19:08:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_empty(int **tab, int &x, int &y)
{
	x = 1;
	y = 1;

	while (x < 5)
	{
		while (y < 5)
		{
			if (tab[x][y] == 0)
				return 1
			y++;
		}
		x++;
	}
	return 0;
}


int		conditions(int **tab, int x, int y, int nb)
{
	
}

int		solve_puzzle(int **tab)
{
	int x;
	int y;
	int nb;

	if (!find_empty(tab, x, y))
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
