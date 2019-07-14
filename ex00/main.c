/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:15:03 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 16:09:59 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "utils.h"

int	main(void)
{
	char str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int tab[SIZE + 2][SIZE + 2] = {
		{0, 4, 3, 2, 1, 0},
		{4, 0, 0, 0, 0, 1},
		{3, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{0, 1, 2, 2, 2, 0}};
	int i;
	int j;

	if (!params_are_valid(str))
		write(1, "Error\n", 7);
	else
	{
		if (!array_is_valid(tab))
			write(1, "Error\n", 7);
		else {
			check_special_cases(tab);
			i = 1;
			while (i <= SIZE)
			{
				j = 1;
				while (j <= SIZE)
				{
					printf("%d ", tab[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
		}
	}
}
