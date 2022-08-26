/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:40:45 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:40:58 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_elem2(t_data *data, char elem)
{
	int	j;
	int	i;
	int	count;

	count = 0;
	j = 0;
	while (j < data->size_line)
	{
		i = 0;
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == elem)
				count++;
			i++;
		}	
		j++;
	}
	return (count);
}	

int	check_map_elem(t_data *data)
{
	int	start;
	int	exit;
	int	collect;

	start = check_map_elem2(data, 'P');
	exit = check_map_elem2(data, 'E');
	collect = check_map_elem2(data, 'C');
	data->mob_number = check_map_elem2(data, 'M');
	if (start == 0 || exit == 0 || collect == 0)
		return (ft_printf("Error\nToo few map elements\n"), 1);
	if (start > 1)
		hide_multiple_players(data);
	if (data->mob_number > 1)
		hide_multiple_mob(data);
	return (0);
}

int	check_map_wall(t_data *data)
{
	int		i;
	int		j;
	int		lenght;

	j = 0;
	lenght = (ft_strlen(data->map[0]) - 1);
	while (j < data->size_line)
	{
		i = 0;
		while (data->map[j][i] != 0 && data->map[j][i] != '\n')
		{
			if (data->map[0][i] != '1' ||
				data->map[data->size_line - 1][i] != '1')
				return (ft_printf("Error\nInvalid wall map\n"), 1);
			if (j > 0 && j < (data->size_line - 1))
			{
				if (data->map[j][0] != '1' || data->map[j][lenght - 1] != '1')
					return (ft_printf("Error\nInvalid wall map\n"), 1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
