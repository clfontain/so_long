/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:19:55 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:39:18 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_str(char **map)
{
	int		i;

	i = 0;
	if (map)
	{
		while (map[i] != NULL)
		{
			free (map[i]);
			i++;
		}
		free (map);
	}	
}

void	destroy_player_and_mob(t_data *data)
{
	if (data->mob_u.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mob_u.mlx_img);
	if (data->mob_d.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mob_d.mlx_img);
	if (data->mob_l.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mob_l.mlx_img);
	if (data->mob_r.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mob_r.mlx_img);
	if (data->player_u.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player_u.mlx_img);
	if (data->player_d.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player_d.mlx_img);
	if (data->player_l.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player_l.mlx_img);
	if (data->player_r.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player_r.mlx_img);
}

void	destroy_all(t_data *data)
{
	destroy_player_and_mob(data);
	if (data->wall.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.mlx_img);
	if (data->floor.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->floor.mlx_img);
	if (data->exit.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->exit.mlx_img);
	if (data->collect.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->collect.mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->end != 1)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		destroy_str(data->map);
	data->win_ptr = NULL;
}

int	button_cross(t_data *data)
{
	data->end = 1;
	destroy_all(data);
	return (0);
}

int	h_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		data->end = 1;
	if (key == XK_w)
		move_up(data);
	if (key == XK_a)
		move_left(data);
	if (key == XK_s)
		move_down(data);
	if (key == XK_d)
		move_right(data);
	if (key)
	{
		if (data->mob_number != 0)
			move_mob(data);
		if (collect_or_not(data) == 0)
			data->map[data->exit_j][data->exit_i] = 'E';
	}
	if (data->end == 1)
	{
		destroy_all(data);
		return (0);
	}	
	return (0);
}
