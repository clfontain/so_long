/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:14:54 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:06:11 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_player(data->map, &i, &j);
	if (data->map[j - 1][i] != '1')
	{
		data->move++;
		animation_move(data, 1);
		ft_printf("%d\n", data->move);
		if (data->map[j - 1][i] == 'E' || data->map[j - 1][i] == 'M')
		{
			data->end = 1;
			return ;
		}	
		data->map[j][i] = '0';
		data->map[j - 1][i] = 'P';
		return ;
	}	
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_player(data->map, &i, &j);
	if (data->map[j + 1][i] != '1')
	{
		data->move++;
		animation_move(data, 2);
		ft_printf("%d\n", data->move);
		if (data->map[j + 1][i] == 'E' || data->map[j + 1][i] == 'M')
		{
			data->end = 1;
			return ;
		}	
		data->map[j][i] = '0';
		data->map[j + 1][i] = 'P';
		return ;
	}	
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_player(data->map, &i, &j);
	if (data->map[j][i - 1] != '1')
	{
		data->move++;
		animation_move(data, 4);
		ft_printf("%d\n", data->move);
		if (data->map[j][i - 1] == 'E' || data->map[j][i - 1] == 'M')
		{
			data->end = 1;
			return ;
		}	
		data->map[j][i] = '0';
		data->map[j][i - 1] = 'P';
		return ;
	}
}		

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	where_is_my_player(data->map, &i, &j);
	if (data->map[j][i + 1] != '1')
	{
		data->move++;
		animation_move(data, 3);
		ft_printf("%d\n", data->move);
		if (data->map[j][i + 1] == 'E' || data->map[j][i + 1] == 'M')
		{
			data->end = 1;
			return ;
		}	
		data->map[j][i] = '0';
		data->map[j][i + 1] = 'P';
		return ;
	}	
}
