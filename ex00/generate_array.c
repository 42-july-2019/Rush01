/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:27:22 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 17:02:23 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void fill_case(int i, int j, int **result, char *params)
{
	if (i == 0 && j != 0 && j != SIZE + 1)
	{
		result[i][j] = params[(j - 1) * 2] - '0';		
	}
	else if(i == SIZE + 1 && j != 0 && j != SIZE + 1)
	{
		result[i][j] = params[(j - 1) * 2 + SIZE * 2] - '0';		
	}
	else if(i != 0 && i != SIZE + 1 && j == 0)
	{
		result[i][j] = params[(i - 1) * 2 + SIZE * 4] - '0';		
	}
	else if(i != 0 && i != SIZE + 1 && j == SIZE + 1)
	{
		result[i][j] = params[(i - 1) * 2 + SIZE * 6] - '0';		
	}
	else
		result[i][j] = 0;
}

int **generate_array(char *params)
{
	int i;
	int j;
	int **result;

	result = 0;
	i = 0;
	result = (int **)malloc(sizeof(int *) * (SIZE + 2));
	while(i < SIZE + 2)
	{
		j = 0;
		result[i] = (int *)malloc(sizeof(int) * (SIZE + 2));
		while (j < SIZE + 2)
		{
			fill_case(i, j, result, params);
			j++;
		}
		i++;
	}
	return (result);
}
