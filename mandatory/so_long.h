/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:42:18 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/25 13:49:02 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>

# define WINDOW_DESTROY_BUTTON 17

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_var
{
	int				x;
	int				y;
	int				end;
	int				player;
	struct s_pos	p_pos;
	int				step;
	int				collect;
	char			**map;
	void			*mlx;
	void			*win;
	void			*img;
	int				img_width;
	int				img_height;
}	t_var;

typedef struct s_node
{
	struct s_pos	pos;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
	int		count;
}	t_queue;

typedef enum e_key
{
	W = 13,
	A = 0,
	S,
	D,
	L = 123,
	R,
	DN,
	UP,
	ESC = 53,
}	t_key;

int		check_map_main(int fd, char *temp, char *name, t_var *var);
void	initial_map_info(t_var *var);
char	*read_map_data(int fd);
int		input_map_info(char *temp, t_var *var);
void	free_map_data(char **map, int y);
int		check_map_escapable(t_var *map);
void	initial_queue(t_var *var, t_queue *queue, int x, int y);
t_pos	dequeue(t_queue *queue);
void	enqueue(t_queue *queue, int x, int y);
void	free_queue(t_queue *queue);
int		draw_field(t_var *var);
void	draw_player_pos(t_var *var, char *temp);
void	draw_tile(t_var *var, int x, int y);
void	draw_wall(t_var *var, int x, int y);
void	draw_collection(t_var *var, int x, int y);
void	draw_exit(t_var *var, int x, int y);
int		window_destroy(int keycode, t_var *var);
int		key_hook(int keycode, t_var *var);
void	key_up(t_var *var);
void	key_down(t_var *var);
void	key_left(t_var *var);
void	key_right(t_var *var);
void	detect_exit(t_var *var);
void	detect_collect(t_var *var);

#endif