/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:14:35 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/22 16:22:33 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_queue(t_var *var, t_queue *queue, int x, int y)
{
	t_node	*new;

	while (var->map[y] != 0)
	{
		x = 0;
		while (var->map[y][x] != 0)
		{
			if (var->map[y][x] == 'P')
			{
				new = (t_node *)malloc(sizeof(t_node));
				new->pos.x = x;
				var->p_pos.x = x;
				new->pos.y = y;
				var->p_pos.y = y;
				new->next = NULL;
				queue->front = new;
				queue->rear = new;
				queue->count = 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	empty(t_queue *queue)
{
	if (queue->count == 0)
		return (1);
	else
		return (0);
}

t_pos	dequeue(t_queue *queue)
{
	t_pos	pos;
	t_node	*node;

	if (empty(queue) == 0)
	{
		node = queue->front;
		pos = node->pos;
		queue->front = node->next;
		free(node);
		(queue->count)--;
	}
	else
	{
		pos.x = 0;
		pos.y = 0;
	}
	return (pos);
}

void	enqueue(t_queue *queue, int y, int x)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->pos.y = y;
	new->pos.x = x;
	new->next = NULL;
	if (empty(queue) == 1)
		queue->front = new;
	else
		queue->rear->next = new;
	queue->rear = new;
	(queue->count)++;
}

void	free_queue(t_queue *queue)
{
	while (empty(queue) == 0)
		dequeue(queue);
}
