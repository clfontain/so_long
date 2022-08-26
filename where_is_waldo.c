/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_waldo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:01:12 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:06:19 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	where_is_my_mob(char **map, int *i, int *j)
{
	int	len;

	len = 0;
	while (map[len] != 0)
		len++;
	while (*j < len)
	{
		*i = 0;
		while (map[*j][*i] != 0)
		{
			if (map[*j][*i] == 'M')
			{
				return ;
			}	
			(*i)++;
		}	
		(*j)++;
	}		
}

void	where_is_my_player(char **map, int *i, int *j)
{
	int	len;

	len = 0;
	while (map[len] != 0)
		len++;
	while (*j < len)
	{
		*i = 0;
		while (map[*j][*i] != 0)
		{
			if (map[*j][*i] == 'P')
			{
				return ;
			}	
			(*i)++;
		}	
		(*j)++;
	}		
}
