/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:17:35 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/13 19:51:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <stdlib.h>
#include "utils.h"
#include <unistd.h>

int		*get_box_from_cond(int n)
{
	int *arr;

	arr = malloc(sizeof(int) * 2);
	if (n >= 3 * SIZE)
	{
		arr[0] = n - 3 * SIZE;
		arr[1] = SIZE - 1;
	}
	else if (n >= 2 * SIZE)
	{
		arr[0] = n - 2 * SIZE;
		arr[1] = 0 ;
	}
	else if (n >= SIZE)
	{
		arr[0] = SIZE - 1;
		arr[1] = n - SIZE;
	}
	else
	{
		arr[0] = 0;
		arr[1] = n;
	}
	return arr;
}

int		get_other_cond_from_box(int *box, int first_cond)
{
	char cond_name;
	int other_cond; 

	cond_name = box[0] < SIZE / 2 ? 'u' : 'd';
	other_cond = cond_name == 'u' ? box[1] : box[1] + SIZE;
	if (other_cond != first_cond)
	{
		return other_cond;
	}
	cond_name = box[1] < SIZE / 2 ? 'l' : 'r';
	other_cond = cond_name == 'l' ? box[0] + SIZE * 2 : box[0] + SIZE * 3;
	return other_cond;
}

void	check_special_cases(int tab[SIZE][SIZE], int *params)
{
	int		i;
	int 	j;
	int		*curr_box;

	i = 0;
	while (i < SIZE * 4)
	{
		curr_box = get_box_from_cond(i);
		if (params[i] == 4)
		{
			tab[curr_box[0]][curr_box[1]] = 1;
			if (i >= 3 * SIZE)
			{
				j = 1;
				while (j < SIZE)
				{
					tab[curr_box[0]][curr_box[1] - j] = SIZE - j - 1;
					j++;
				}
			}
			else if (i >= 2 * SIZE)
			{
				j = 1;
				while (j < SIZE)
				{
					tab[curr_box[0]][curr_box[1] + j] = j + 1;
					j++;
				}
			}
			else if (i >= SIZE)
			{
				j = 1;
				while (j < SIZE)
				{
					tab[curr_box[0] - j][curr_box[1]] = SIZE - j - 1;
					j++;
				}
			}
			else
			{
				j = 1;
				while (j < SIZE)
				{
					tab[curr_box[0] + j][curr_box[1]] = j + 1;
					j++;
				}
			}
		}
		else if (params[i] == 1)
		{
			j = get_other_cond_from_box(curr_box, i);
			if (params[j] == 1)
				tab[curr_box[0]][curr_box[1]] = 4;
		}
		i++;
		free(curr_box);
	}
}
