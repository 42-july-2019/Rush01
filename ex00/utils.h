/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:15:45 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/14 13:56:17 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define SIZE 4

void	check_up_conditions(int tab[SIZE + 2][SIZE + 2]);
void	check_down_conditions(int tab[SIZE + 2][SIZE + 2]);
void	check_left_conditions(int tab[SIZE + 2][SIZE + 2]);
void	check_right_conditions(int tab[SIZE + 2][SIZE + 2]);
void	check_special_cases(int tab[SIZE + 2][SIZE + 2]);

#endif
