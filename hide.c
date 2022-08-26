/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:43:36 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:46:51 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hide_multiple_players(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	j = 0;
	while (j < data->size_line)
	{
		i = 0;
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == 'P')
			{
				x = i;
				y = j;
				data->map[j][i] = '0';
			}	
			i++;
		}
		j++;
	}
	data->map[y][x] = 'P';
}

void	hide_multiple_mob(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	j = 0;
	while (j < data->size_line)
	{
		i = 0;
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == 'M')
			{
				x = i;
				y = j;
				data->map[j][i] = '0';
			}	
			i++;
		}
		j++;
	}
	data->map[y][x] = 'M';
}

void	hide_the_exit(t_data *data)
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
			if (data->map[j][i] == 'E')
			{
				data->map[j][i] = '0';
				data->exit_i = i;
				data->exit_j = j;
			}
			i++;
		}
		j++;
	}
}
