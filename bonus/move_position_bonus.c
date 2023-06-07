/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:04:11 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 14:08:09 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_up(t_var *var, int flag)
{
	t_pos	pos;
	char	*dir;

	pos = check_pos(var, flag, 0, &dir);
	if (var->map[pos.y - 1][pos.x] != '1')
	{
		re_draw(var, pos, flag);
		if (flag == 0)
			(var->p_pos.y)--;
		else
			(var->e_pos.y)--;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E' && flag == 0)
			detect_exit(var, dir);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C' && flag == 0)
			detect_collect(var, dir);
		else
			draw_player_pos(var, dir, flag);
		if (flag == 0)
			var->p_step++;
	}
}

void	key_down(t_var *var, int flag)
{
	t_pos	pos;
	char	*dir;

	pos = check_pos(var, flag, 1, &dir);
	if (var->map[pos.y + 1][pos.x] != '1')
	{
		re_draw(var, pos, flag);
		if (flag == 0)
			(var->p_pos.y)++;
		else
			(var->e_pos.y)++;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E' && flag == 0)
			detect_exit(var, dir);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C' && flag == 0)
			detect_collect(var, dir);
		else
			draw_player_pos(var, dir, flag);
		if (flag == 0)
			var->p_step++;
	}
}

void	key_left(t_var *var, int flag)
{
	t_pos	pos;
	char	*dir;

	pos = check_pos(var, flag, 2, &dir);
	if (var->map[pos.y][pos.x - 1] != '1')
	{
		re_draw(var, pos, flag);
		if (flag == 0)
			(var->p_pos.x)--;
		else
			(var->e_pos.x)--;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E' && flag == 0)
			detect_exit(var, dir);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C' && flag == 0)
			detect_collect(var, dir);
		else
			draw_player_pos(var, dir, flag);
		if (flag == 0)
			var->p_step++;
	}
}

void	key_right(t_var *var, int flag)
{
	t_pos	pos;
	char	*dir;

	pos = check_pos(var, flag, 3, &dir);
	if (var->map[pos.y][pos.x + 1] != '1')
	{
		re_draw(var, pos, flag);
		if (flag == 0)
			(var->p_pos.x)++;
		else
			(var->e_pos.x)++;
		if (var->map[var->p_pos.y][var->p_pos.x] == 'E' && flag == 0)
			detect_exit(var, dir);
		else if (var->map[var->p_pos.y][var->p_pos.x] == 'C' && flag == 0)
			detect_collect(var, dir);
		else
			draw_player_pos(var, dir, flag);
		if (flag == 0)
			var->p_step++;
	}
}
