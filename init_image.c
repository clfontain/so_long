/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:02:16 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:23:32 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_image3(t_data *data)
{
	if (init_image2(data, &data->mob_u, "image/mob_up.xpm") == 1)
		return (1);
	if (init_image2(data, &data->mob_d, "image/mob_down.xpm") == 1)
		return (1);
	if (init_image2(data, &data->mob_l, "image/mob_left.xpm") == 1)
		return (1);
	if (init_image2(data, &data->mob_r, "image/mob_right.xpm") == 1)
		return (1);
	return (0);
}

int	init_image2(t_data *data, t_img *img, char *name)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, name,
			&img->width, &img->height);
	if (img->mlx_img == NULL)
	{
		printf("Error\nImage Initialization Failed\n");
		destroy_all(data);
		return (1);
	}
	if (img->width != 50 || img->height != 50)
	{
		printf("Error\nWrong Image Size, Only 50 * 50 pixels allowed\n");
		destroy_all(data);
		return (1);
	}		
	return (0);
}

int	init_image(t_data *data)
{
	if (init_image2(data, &data->wall, "image/wall.xpm") == 1)
		return (1);
	if (init_image2(data, &data->player_u, "image/player_look_up.xpm") == 1)
		return (1);
	if (init_image2(data, &data->player_d, "image/player_look_down.xpm") == 1)
		return (1);
	if (init_image2(data, &data->player_r, "image/player_look_right.xpm") == 1)
		return (1);
	if (init_image2(data, &data->player_l, "image/player_look_left.xpm") == 1)
		return (1);
	if (init_image2(data, &data->collect, "image/collect.xpm") == 1)
		return (1);
	if (init_image2(data, &data->exit, "image/exit.xpm") == 1)
		return (1);
	if (init_image2(data, &data->floor, "image/floor.xpm") == 1)
		return (1);
	if (init_image3(data) == 1)
		return (1);
	return (0);
}
