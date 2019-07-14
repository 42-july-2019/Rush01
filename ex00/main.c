/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:15:03 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 18:22:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_array(int *tab[SIZE + 2])
{
	int i;
	int j;

	i = 1;
	while (i <= SIZE)
	{
		j = 1;
		while (j <= SIZE)
		{
			ft_putchar(tab[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\n", 7);
	}
	else
	{		
		char *str;
		int **array;

		str = argv[1];
		if (!params_are_valid(str))
			write(1, "Error\n", 7);
		else
		{
			array = generate_array(str);
			if (!array_is_valid(array))
				write(1, "Error\n", 7);
			else {
				check_special_cases(array);
				print_array(array);
			}
		}
	}
}
