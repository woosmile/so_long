/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_main_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:47:09 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/26 17:44:17 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_name(char *name)
{
	size_t	len;
	char	*cmp;

	len = ft_strlen(name);
	cmp = ".ber";
	if (ft_strncmp(&name[len - 4], cmp, 4) == 0)
		return (0);
	else
	{
		ft_printf("Error\nCause : invalid map file name.\n");
		return (1);
	}
}

int	check_map_info(char *temp, t_var *var)
{
	if (var->end != 1)
	{
		ft_printf("Error\nCause : invalid exit position.\n");
		free(temp);
		return (1);
	}
	else if (var->collect < 1)
	{
		ft_printf("Error\nCause : empty collection.\n");
		free(temp);
		return (1);
	}
	else if (var->player != 1 || var->enemy != 1)
	{
		ft_printf("Error\nCause : invalid player or enemy position.\n");
		free(temp);
		return (1);
	}
	else if (var->y < 3)
	{
		ft_printf("Error\nCause : too small column.\n");
		free(temp);
		return (1);
	}
	return (0);
}

int	check_edge(t_var *var, int x, int y)
{
	size_t	len;

	while (var->map[y] != 0)
	{
		if (y == 0 || y == var->y - 1)
		{
			x = 0;
			while (var->map[y][x] != 0)
			{
				if (var->map[y][x] != '1')
					return (1);
				x++;
			}
			var->x = x;
		}
		else
		{
			len = ft_strlen(var->map[y]) - 1;
			if (var->map[y][0] != '1' || var->map[y][len] != '1')
				return (1);
		}
		y++;
	}
	return (0);
}

int	check_rectangular(t_var *var, int result, int i, size_t len)
{
	while (i < var->y - 1)
	{
		len = ft_strlen(var->map[i]);
		if ((int)len != var->x)
		{
			result = 1;
			break ;
		}
			i++;
	}
	if (result == 1)
	{
		ft_printf("Error\nCause : invalid rectangular.\n");
		free_map_data(var->map, var->y);
		return (1);
	}
	return (0);
}

int	check_map_main(int fd, char *temp, char *name, t_var *var)
{
	initial_map_info(var);
	if (check_map_name(name) == 1)
		return (1);
	temp = read_map_data(fd);
	if (!temp)
		return (1);
	if (input_map_info(temp, var) == 1)
		return (1);
	var->map = ft_split(temp, '\n');
	while (var->map[var->y] != 0)
		(var->y)++;
	if (check_map_info(temp, var) == 1)
		return (1);
	free(temp);
	if (check_edge(var, 0, 0) == 1)
	{
		ft_printf("Error\nCause : empty space at the edge of the map.\n");
		free_map_data(var->map, var->y);
		return (1);
	}
	if (check_rectangular(var, 0, 0, 0) == 1)
		return (1);
	if (check_map_escapable(var) == 1)
		return (1);
	return (0);
}
