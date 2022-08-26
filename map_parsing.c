/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:11:30 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/15 12:41:35 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_str_map(t_data *data, int size_line)
{
	int	fd2;
	int	i;

	i = 0;
	fd2 = open(data->map_name, O_RDONLY);
	if (fd2 < 0)
		return (ft_printf("Error\nOpen failed\n"), NULL);
	while (i < size_line + 1)
	{
		data->map[i] = get_next_line(fd2);
		i++;
	}
	close(fd2);
	return (data->map);
}

int	count_line(t_data *data)
{
	char	*str;
	int		fd;

	data->size_line = 0;
	fd = open(data->map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nOpen failed\n"), 1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		data->size_line++;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close(fd);
	return (0);
}	

char	**parse_map(t_data *data)
{
	if (count_line(data) == 1)
		return (NULL);
	data->map = malloc(sizeof(char *) * (data->size_line + 1));
	if (data->map == NULL)
		return (ft_printf("Error\nMalloc Allocation Failed\n"), NULL);
	if (init_str_map(data, data->size_line) == NULL)
		return (destroy_str(data->map), NULL);
	if (check_map_size(data) == 1 || check_map_elem(data) == 1
		|| check_map_wall(data) == 1)
		return (destroy_str(data->map), NULL);
	size_map(data->map, data->size_line, data);
	return (data->map);
}
