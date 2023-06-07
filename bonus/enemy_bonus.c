/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:36:59 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 14:00:33 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy_pos(t_var *var, int x, int y)
{
	while (var->map[y] != 0)
	{
		x = 0;
		while (var->map[y][x] != 0)
		{
			if (var->map[y][x] == 'X')
			{
				var->e_pos.x = x;
				var->e_pos.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	move_enemy(t_var *var)
{	
	int	num;
	int	delay;

	num = rand() % 4;
	delay = 0;
	while (delay < 80000000)
		delay++;
	if (num == 0)
		key_up(var, 1);
	else if (num == 1)
		key_down(var, 1);
	else if (num == 2)
		key_left(var, 1);
	else if (num == 3)
		key_right(var, 1);
	enemy_encountered(var);
	var->e_step++;
	return (0);
}
