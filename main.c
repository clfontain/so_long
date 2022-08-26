/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:21:54 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:23:04 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	data->wall.mlx_img = NULL;
	data->player_u.mlx_img = NULL;
	data->player_r.mlx_img = NULL;
	data->player_l.mlx_img = NULL;
	data->player_d.mlx_img = NULL;
	data->mob_u.mlx_img = NULL;
	data->mob_r.mlx_img = NULL;
	data->mob_l.mlx_img = NULL;
	data->mob_d.mlx_img = NULL;
	data->exit.mlx_img = NULL;
	data->collect.mlx_img = NULL;
	data->floor.mlx_img = NULL;
	data->mlx_ptr = NULL;
	data->move = 0;
	data->trigger = 0;
	data->end = 0;
	data->win_ptr = NULL;
	data->map = NULL;
	data->player_down = 1;
	data->player_up = 0;
	data->player_right = 0;
	data->player_left = 0;
}

int	init_2(t_data *data)
{
	data->mob_left = 1;
	data->mob_up = 0;
	data->mob_right = 0;
	data->mob_down = 0;
	data->map = parse_map(data);
	if (data->map == NULL)
		return (1);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (destroy_str(data->map), ft_printf("Error\nMlx error\n"), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "So_long");
	if (data->win_ptr == NULL)
		return (destroy_all(data), ft_printf("Error\nWindow error\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error\nInvalid Arguments\n"), 1);
	if (check_map_name(argv[1]) == 1)
		return (ft_printf("Error\nInvalid map name\n"), 1);
	data.map_name = argv[1];
	init(&data);
	if (init_2(&data) == 1)
		return (1);
	if (init_image(&data) == 1)
		return (1);
	hide_the_exit(&data);
	mlx_loop_hook(data.mlx_ptr, &display, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &h_keypress, &data);
	mlx_hook(data.win_ptr, 33, 0, &button_cross, &data);
	mlx_loop (data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
