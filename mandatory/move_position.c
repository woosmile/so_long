/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:04:11 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/24 19:43:13 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_var *var)
{
	if (var->map[var->p_pos.y - 1][var->p_pos.x] != '1')
	{
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
		{
			draw_player_pos(var, "xpm/tile.xpm");
			draw_player_pos(var, "xpm/exit.xpm");
		}
		else
			draw_player_pos(var, "xpm/tile.xpm");
		(var->p_pos.y)--;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
			detect_exit(var);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C')
			detect_collect(var);
		else
			draw_player_pos(var, "xpm/p_front.xpm");
		var->step++;
	}
}

void	key_down(t_var *var)
{
	if (var->map[var->p_pos.y + 1][var->p_pos.x] != '1')
	{
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
		{
			draw_player_pos(var, "xpm/tile.xpm");
			draw_player_pos(var, "xpm/exit.xpm");
		}
		else
			draw_player_pos(var, "xpm/tile.xpm");
		(var->p_pos.y)++;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
			detect_exit(var);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C')
			detect_collect(var);
		else
			draw_player_pos(var, "xpm/p_front.xpm");
		var->step++;
	}
}

void	key_left(t_var *var)
{
	if (var->map[var->p_pos.y][var->p_pos.x - 1] != '1')
	{
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
		{
			draw_player_pos(var, "xpm/tile.xpm");
			draw_player_pos(var, "xpm/exit.xpm");
		}
		else
			draw_player_pos(var, "xpm/tile.xpm");
		(var->p_pos.x)--;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
			detect_exit(var);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C')
			detect_collect(var);
		else
			draw_player_pos(var, "xpm/p_front.xpm");
		var->step++;
	}
}

void	key_right(t_var *var)
{
	if (var->map[var->p_pos.y][var->p_pos.x + 1] != '1')
	{
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
		{
			draw_player_pos(var, "xpm/tile.xpm");
			draw_player_pos(var, "xpm/exit.xpm");
		}
		else
			draw_player_pos(var, "xpm/tile.xpm");
		(var->p_pos.x)++;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E')
			detect_exit(var);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C')
			detect_collect(var);
		else
			draw_player_pos(var, "xpm/p_front.xpm");
		var->step++;
	}
}
