/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:27:45 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:46:09 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_map(char **map, int size_line, t_data *data)
{
	data->height = (size_line * 50);
	data->width = ((ft_strlen(map[0]) - 1) * 50);
}

int	check_map_name(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 4;
	if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e'
		&& argv[i + 3] == 'r' && i != 4)
		return (0);
	return (1);
}

int	check_map_size(t_data *data)
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
			i++;
		if (i != lenght)
			return (ft_printf("Error\nInvalid size map\n"), 1);
		j++;
	}
	return (0);
}
