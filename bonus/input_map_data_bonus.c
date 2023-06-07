/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_data_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:22:06 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/24 17:57:32 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initial_map_info(t_var *var)
{
	var->x = 0;
	var->y = 0;
	var->end = 0;
	var->player = 0;
	var->enemy = 0;
	var->collect = 0;
	var->map = NULL;
	var->p_step = 0;
	var->e_step = 0;
}

char	*read_map_data(int fd)
{
	char	word[2];
	char	*temp;
	int		read_len;

	temp = ft_strdup("");
	read_len = read(fd, word, 1);
	word[1] = 0;
	if (!read_len)
	{
		ft_printf("Error\nCause : failed read map data.\n");
		return (NULL);
	}
	while (read_len != 0)
	{
		temp = ft_strjoin(temp, word);
		read_len = read(fd, word, 1);
		word[1] = 0;
	}
	return (temp);
}

int	input_map_info(char *temp, t_var *var)
{
	int	i;

	i = 0;
	while (temp[i] != 0)
	{
		if (temp[i] == 'E')
			(var->end)++;
		else if (temp[i] == 'C')
			(var->collect)++;
		else if (temp[i] == 'P')
			(var->player)++;
		else if (temp[i] == 'X')
			(var->enemy)++;
		else if (temp[i] != '1' && temp[i] != '\n' && temp[i] != '0')
		{
			ft_printf("Error\nCause : invalid word.\n");
			free(temp);
			return (1);
		}
		i++;
	}
	return (0);
}
