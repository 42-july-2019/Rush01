/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:15:03 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 17:22:30 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "utils.h"

int	main(int argc, char **argv)
{
	char *str;
	if (argc < 2)
	{
		//write(1, "Error\n", 7);
		str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

	}
	else
	{		
		str = argv[1];
		// insert rest of main here...
	}
	int **array;
	int i;
	int j;

	array = generate_array(str);
	if (!params_are_valid(str))
		write(1, "Error\n", 7);
	else
	{
		if (!array_is_valid(array))
			write(1, "Error\n", 7);
		else {
			check_special_cases(array);
			i = 0;
			while (i <= SIZE + 1)
			{
				j = 0;
				while (j <= SIZE + 1)
				{
					printf("%d ", array[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
		}
	}
}
