/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:17:35 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 11:52:13 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/*
** 	up		-> 	i = 0, 			j ∈ [1, SIZE]
** 	down	-> 	i = SIZE + 1, 	j ∈ [1, SIZE]
** 	left	-> 	i ∈ [1, SIZE], 	j = 0
** 	right	-> 	i ∈ [1, SIZE], 	j = SIZE + 1
*/

void	check_special_cases(int tab[SIZE + 2][SIZE + 2])
{
	check_up_conditions(tab);
	check_down_conditions(tab);
	check_left_conditions(tab);
	check_right_conditions(tab);
}
