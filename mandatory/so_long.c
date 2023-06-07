/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:42:09 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 13:49:12 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	int		fd;
	t_var	var;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCause : failed open map file.\n");
		return (1);
	}
	if (check_map_main(fd, 0, av[1], &var) == 1)
		return (1);
	if (draw_field(&var) == 1)
		return (1);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, WINDOW_DESTROY_BUTTON, 0, window_destroy, &var);
	mlx_loop(var.mlx);
	free_map_data(var.map, var.y);
	return (0);
}
