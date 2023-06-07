/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:38:27 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/24 16:51:45 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	detect_exit(t_var *var, char *dir)
{
	if (var->collect == 0)
	{
		ft_printf("You collected all the swords. Awesome!\n");
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	else
	{
		draw_player_pos(var, dir, 0);
		ft_printf("There are %d swords left on the field.\n", var->collect);
	}
}

void	detect_collect(t_var *var, char *dir)
{
	if (var->collect > 0)
	{
		var->collect--;
		var->map[var->p_pos.y][var->p_pos.x] = '0';
		draw_player_pos(var, "xpm/tile.xpm", 0);
		draw_player_pos(var, dir, 0);
	}
}
