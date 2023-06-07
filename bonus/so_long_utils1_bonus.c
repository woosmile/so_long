/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:50:46 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 13:58:29 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map_data(char **map, int y)
{
	int	i;

	i = 0;
	while (i <= y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	draw_field(t_var *var)
{
	var->mlx = mlx_init();
	if (var->mlx == NULL)
	{
		ft_printf("Error\nCause : failed initial mlx.\n");
		return (1);
	}
	var->win = mlx_new_window(var->mlx, var->x * 32, var->y * 32, "so_long");
	if (var->win == NULL)
	{
		ft_printf("Error\nCause : failed create window.\n");
		return (1);
	}
	draw_tile(var, 0, 0);
	draw_wall(var, 0, 0);
	draw_collection(var, 0, 0);
	draw_exit(var, 0, 0);
	draw_player_pos(var, var->p_sprite[1][1], 0);
	draw_player_pos(var, var->e_sprite[1][1], 1);
	draw_step(var);
	return (0);
}

int	window_destroy(int keycode, t_var *var)
{
	(void)keycode;
	(void)var;
	exit(0);
}

int	key_hook(int keycode, t_var *var)
{
	t_key	key;
	int		temp_step;

	key = keycode;
	temp_step = var->p_step;
	if (key == W || key == UP)
		key_up(var, 0);
	else if (key == S || key == DN)
		key_down(var, 0);
	else if (key == A || key == L)
		key_left(var, 0);
	else if (key == D || key == R)
		key_right(var, 0);
	else if (key == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	if (temp_step != var->p_step)
		draw_step(var);
	enemy_encountered(var);
	return (0);
}
