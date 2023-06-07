/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:44:12 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 13:48:11 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	draw_player_pos(var, "xpm/p_front.xpm");
	ft_printf("Steps : %d\n", var->step);
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
	temp_step = var->step;
	if (key == W || key == UP)
		key_up(var);
	else if (key == S || key == DN)
		key_down(var);
	else if (key == A || key == L)
		key_left(var);
	else if (key == D || key == R)
		key_right(var);
	else if (key == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	if (temp_step != var->step)
		ft_printf("Steps : %d\n", var->step);
	return (0);
}
