/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:13:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 09:55:08 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_mob_image(t_data *data, int i, int j)
{
	if (data->mob_up == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mob_u.mlx_img, (i * 50), (j * 50));
	if (data->mob_down == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mob_d.mlx_img, (i * 50), (j * 50));
	if (data->mob_right == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mob_r.mlx_img, (i * 50), (j * 50));
	if (data->mob_left == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mob_l.mlx_img, (i * 50), (j * 50));
}

void	display_player_image(t_data *data, int i, int j)
{
	if (data->player_up == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_u.mlx_img, (i * 50), (j * 50));
	if (data->player_down == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_d.mlx_img, (i * 50), (j * 50));
	if (data->player_right == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_r.mlx_img, (i * 50), (j * 50));
	if (data->player_left == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_l.mlx_img, (i * 50), (j * 50));
}

int	collect_or_not(t_data *data)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	len = 0;
	while (data->map[len] != 0)
		len++;
	while (j < len)
	{
		i = 0;
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	display_image(t_data *data, char c, int j, int i)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor.mlx_img, (i * 50), (j * 50));
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall.mlx_img, (i * 50), (j * 50));
	if (c == 'P')
		display_player_image(data, i, j);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit.mlx_img, (i * 50), (j * 50));
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect.mlx_img, (i * 50), (j * 50));
	if (c == 'M')
		display_mob_image(data, i, j);
	return (0);
}

int	display(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (j < data->size_line)
	{
		i = 0;
		while (data->map[j][i] != 0)
		{
			display_image(data, data->map[j][i], j, i);
			i++;
		}
		j++;
	}
	return (0);
}
