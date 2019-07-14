/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:14:06 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 17:12:59 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		params_are_valid(char *str)
{
	int i;
	int curr_digit;

	i = 0;
	while (str[i] >= '1' && str[i] <= '9' &&
			(str[i + 1] == ' ' || !str[i + 1]))
	{
		curr_digit = str[i] - '0';
		if (curr_digit > SIZE)
			return 0;
		i = i + 2;
	}
	if (i != SIZE * 4 * 2)
		return (0);
	return (1);
}

int		duo_is_valid(int param1, int param2)
{
	if ((param1 == SIZE && param2 != 1) ||
			(param1 != 1 && param2 == SIZE ))
		return (0);
	if ((param1 == 1 && param2 == 1) ||
			(param1 == 1 && param2 == 1 ))
		return (0);
	if ((param1 == SIZE - 1 && param2 != 2) ||
			(param1 != 2  && param2 == SIZE - 1))
		return (0);
	if (param1 + param2 > SIZE + 1)
		return (0);
	return (1);
}

int		array_is_valid(int *tab[SIZE + 2])
{
	int i;
	int j;
	int opp_param;

	i = 0;
	j = 1;
	while (j <= SIZE)
	{
		opp_param = tab[SIZE + 1][j];
		if (!duo_is_valid(tab[i][j], opp_param))
			return (0);
		j++;
	}
	i = 1;
	j = 0;
	while (i <= SIZE)
	{
		opp_param = tab[i][SIZE + 1];
		if (!duo_is_valid(tab[i][j], opp_param))
			return (0);
		i++;
	}
	return (1);
}
