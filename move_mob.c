/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:57:27 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:05:56 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_mob(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_mob(data->map, &i, &j);
	if (data->trigger == 0)
		move_mob_left(data);
	if (data->trigger == 1)
		move_mob_down(data);
	if (data->trigger == 2)
		move_mob_right(data);
	if (data->trigger == 3)
		move_mob_up(data);
}

void	move_mob_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_mob(data->map, &i, &j);
	while (data->map[j][i - 1] != '1' && data->map[j][i - 1] != 'E'
		&& data->map[j][i - 1] != 'C')
	{
		animation_mob_move(data, 4);
		if (data->map[j][i - 1] == 'P')
			data->end = 1;
		data->map[j][i] = '0';
		data->map[j][i - 1] = 'M';
		return ;
	}
	data->trigger = 1;
}

void	move_mob_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_mob(data->map, &i, &j);
	if (data->map[j + 1][i] != '1' && data->map[j + 1][i] != 'E'
		&& data->map[j + 1][i] != 'C')
	{
		animation_mob_move(data, 2);
		if (data->map[j + 1][i] == 'P')
		data->end = 1;
		data->map[j][i] = '0';
		data->map[j + 1][i] = 'M';
		return ;
	}
	data->trigger = 2;
}

void	move_mob_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_mob(data->map, &i, &j);
	if (data->map[j][i + 1] != '1' && data->map[j][i + 1] != 'E'
		&& data->map[j][i + 1] != 'C')
	{
		animation_mob_move(data, 3);
		if (data->map[j][i + 1] == 'P')
		data->end = 1;
		data->map[j][i] = '0';
		data->map[j][i + 1] = 'M';
		return ;
	}
	data->trigger = 3;
}

void	move_mob_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_mob(data->map, &i, &j);
	if (data->map[j - 1][i] != '1' && data->map[j - 1][i] != 'E'
		&& data->map[j - 1][i] != 'C')
	{
		animation_mob_move(data, 1);
		if (data->map[j - 1][i] == 'P')
		data->end = 1;
		data->map[j][i] = '0';
		data->map[j - 1][i] = 'M';
		return ;
	}	
	data->trigger = 0;
}
