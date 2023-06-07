/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:38:58 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 13:57:26 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initial_sprite(t_var *var)
{
	var->p_sprite[0][0] = "xpm_sprite/p_rear_0.xpm";
	var->p_sprite[0][1] = "xpm_sprite/p_rear_1.xpm";
	var->p_sprite[0][2] = "xpm_sprite/p_rear_2.xpm";
	var->p_sprite[1][0] = "xpm_sprite/p_front_0.xpm";
	var->p_sprite[1][1] = "xpm_sprite/p_front_1.xpm";
	var->p_sprite[1][2] = "xpm_sprite/p_front_2.xpm";
	var->p_sprite[2][0] = "xpm_sprite/p_left_0.xpm";
	var->p_sprite[2][1] = "xpm_sprite/p_left_1.xpm";
	var->p_sprite[2][2] = "xpm_sprite/p_left_2.xpm";
	var->p_sprite[3][0] = "xpm_sprite/p_right_0.xpm";
	var->p_sprite[3][1] = "xpm_sprite/p_right_1.xpm";
	var->p_sprite[3][2] = "xpm_sprite/p_right_2.xpm";
	var->e_sprite[0][0] = "xpm_sprite/e_rear_0.xpm";
	var->e_sprite[0][1] = "xpm_sprite/e_rear_1.xpm";
	var->e_sprite[0][2] = "xpm_sprite/e_rear_2.xpm";
	var->e_sprite[1][0] = "xpm_sprite/e_front_0.xpm";
	var->e_sprite[1][1] = "xpm_sprite/e_front_1.xpm";
	var->e_sprite[1][2] = "xpm_sprite/e_front_2.xpm";
	var->e_sprite[2][0] = "xpm_sprite/e_left_0.xpm";
	var->e_sprite[2][1] = "xpm_sprite/e_left_1.xpm";
	var->e_sprite[2][2] = "xpm_sprite/e_left_2.xpm";
	var->e_sprite[3][0] = "xpm_sprite/e_right_0.xpm";
	var->e_sprite[3][1] = "xpm_sprite/e_right_1.xpm";
	var->e_sprite[3][2] = "xpm_sprite/e_right_2.xpm";
}

t_pos	check_pos(t_var *var, int flag, int way, char **dir)
{
	t_pos	pos;

	if (flag == 0)
	{
		pos.x = var->p_pos.x;
		pos.y = var->p_pos.y;
		*dir = var->p_sprite[way][var->p_step % 3];
	}
	else
	{
		pos.x = var->e_pos.x;
		pos.y = var->e_pos.y;
		*dir = var->e_sprite[way][var->e_step % 3];
	}
	return (pos);
}

void	draw_step(t_var *var)
{
	char	*num;

	var->img = mlx_xpm_file_to_image(var->mlx, "xpm/tile.xpm", \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", "xpm/tile.xpm");
		exit(1);
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 32, 0);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 32, 32);
	var->img = mlx_xpm_file_to_image(var->mlx, "xpm/wall.xpm", \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", "xpm/wall.xpm");
		exit(1);
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 32, 0);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 32, 32);
	num = ft_itoa(var->p_step);
	mlx_string_put(var->mlx, var->win, 32, 36, 0xFF0000, num);
	free(num);
}

void	re_draw(t_var *var, t_pos pos, int flag)
{
	if (var->map[pos.y][pos.x] == 'E')
	{
		draw_player_pos(var, "xpm/tile.xpm", flag);
		draw_player_pos(var, "xpm/exit.xpm", flag);
	}
	else if (var->map[pos.y][pos.x] == 'C' && flag == 1)
	{
		draw_player_pos(var, "xpm/tile.xpm", flag);
		draw_player_pos(var, "xpm/collection.xpm", flag);
	}
	else
		draw_player_pos(var, "xpm/tile.xpm", flag);
}

void	enemy_encountered(t_var *var)
{
	if ((var->p_pos.x == var->e_pos.x) && (var->p_pos.y == var->e_pos.y))
	{
		ft_printf("Oops! The player encountered an enemy!\n");
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
}
