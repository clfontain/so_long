/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:49:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 09:55:14 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_move(t_data *data, int direction)
{
	data->player_up = 0;
	data->player_down = 0;
	data->player_right = 0;
	data->player_left = 0;
	if (direction == 1)
		data->player_up = 1;
	if (direction == 2)
		data->player_down = 1;
	if (direction == 3)
		data->player_right = 1;
	if (direction == 4)
		data->player_left = 1;
}

void	animation_mob_move(t_data *data, int direction)
{
	data->mob_up = 0;
	data->mob_down = 0;
	data->mob_right = 0;
	data->mob_left = 0;
	if (direction == 1)
		data->mob_up = 1;
	if (direction == 2)
		data->mob_down = 1;
	if (direction == 3)
		data->mob_right = 1;
	if (direction == 4)
		data->mob_left = 1;
}
