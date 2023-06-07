/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:35:19 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/24 19:24:55 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player_pos(t_var *var, char *dir, int flag)
{
	var->img = mlx_xpm_file_to_image(var->mlx, dir, \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", dir);
		exit(1);
	}
	if (flag == 0)
		mlx_put_image_to_window(var->mlx, var->win, var->img, \
				var->p_pos.x * var->img_width, var->p_pos.y * var->img_height);
	else
		mlx_put_image_to_window(var->mlx, var->win, var->img, \
				var->e_pos.x * var->img_width, var->e_pos.y * var->img_height);
}

void	draw_tile(t_var *var, int x, int y)
{
	char	*dir;

	dir = "xpm/tile.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, dir, \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", dir);
		exit(1);
	}
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->img, \
								x * var->img_width, y * var->img_height);
			x++;
		}
		y++;
	}
}

void	draw_wall(t_var *var, int x, int y)
{
	char	*dir;

	dir = "xpm/wall.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, dir, \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", dir);
		exit(1);
	}
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (var->map[y][x] == '1')
				mlx_put_image_to_window(var->mlx, var->win, var->img, \
									x * var->img_width, y * var->img_height);
			x++;
		}
		y++;
	}
}

void	draw_collection(t_var *var, int x, int y)
{
	char	*dir;

	dir = "xpm/collection.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, dir, \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", dir);
		exit(1);
	}
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (var->map[y][x] == 'C')
				mlx_put_image_to_window(var->mlx, var->win, var->img, \
									x * var->img_width, y * var->img_height);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_var *var, int x, int y)
{
	char	*dir;

	dir = "xpm/exit.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, dir, \
									&(var->img_width), &(var->img_height));
	if (var->img == NULL)
	{
		ft_printf("Error\nCause : failed create %s image.\n", dir);
		exit(1);
	}
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (var->map[y][x] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->img, \
									x * var->img_width, y * var->img_height);
				return ;
			}
			x++;
		}
		y++;
	}
}
