/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_escapable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:39:19 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/24 11:44:12 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**initial_visit(t_var *var)
{
	char	**visit;
	int		y;

	visit = (char **)malloc(sizeof(char *) * var->y);
	y = 0;
	while (y < var->y)
	{
		visit[y] = ft_strdup(var->map[y]);
		y++;
	}
	return (visit);
}

int	player_to_exit(t_queue *queue, t_var var, char **visit, int i)
{
	t_pos		check;
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};

	while (queue->count > 0)
	{
		check = dequeue(queue);
		i = 0;
		while (i < 4)
		{
			if (var.map[check.y + dy[i]][check.x + dx[i]] == 'E')
				return (0);
			else if (((var.map[check.y + dy[i]][check.x + dx[i]] == '0') || \
				(var.map[check.y + dy[i]][check.x + dx[i]] == 'C')) && \
				((visit[check.y + dy[i]][check.x + dx[i]] == '0') || \
				(visit[check.y + dy[i]][check.x + dx[i]] == 'C')))
			{
				visit[check.y + dy[i]][check.x + dx[i]] = '1';
				enqueue(queue, check.y + dy[i], check.x + dx[i]);
			}
			i++;
		}
	}
	ft_printf("Error\nCause : an inescapable map.\n");
	return (1);
}

int	player_to_collection(t_queue *queue, t_var var, char **visit, int i)
{
	t_pos		check;
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};

	while (queue->count > 0)
	{
		check = dequeue(queue);
		i = 0;
		while (i < 4)
		{
			if ((var.map[check.y + dy[i]][check.x + dx[i]] != '1') &&
				(visit[check.y + dy[i]][check.x + dx[i]] != '1'))
			{
				if (var.map[check.y + dy[i]][check.x + dx[i]] == 'C')
					var.collect--;
				visit[check.y + dy[i]][check.x + dx[i]] = '1';
				enqueue(queue, check.y + dy[i], check.x + dx[i]);
			}
			i++;
		}
	}
	if (var.collect == 0)
		return (0);
	else
		return (1);
}

int	check_map_escapable(t_var *var)
{
	t_queue	queue;
	char	**visit;

	visit = initial_visit(var);
	initial_queue(var, &queue, 0, 0);
	visit[queue.front->pos.y][queue.front->pos.x] = '1';
	if (player_to_exit(&queue, *var, visit, 0) == 1)
		exit(1);
	free_map_data(visit, var->y - 1);
	free_queue(&queue);
	visit = initial_visit(var);
	initial_queue(var, &queue, 0, 0);
	if (player_to_collection(&queue, *var, visit, 0) == 1)
	{
		ft_printf("Error\nCause : inaccessible map for collection.\n");
		exit(1);
	}
	free_map_data(visit, var->y - 1);
	return (0);
}
