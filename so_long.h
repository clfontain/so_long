/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:02:03 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/20 10:47:03 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	wall;
	t_img	player_u;
	t_img	player_d;
	t_img	player_r;
	t_img	player_l;
	t_img	collect;
	t_img	mob_u;
	t_img	mob_d;
	t_img	mob_l;
	t_img	mob_r;
	int		mob_number;
	t_img	exit;
	t_img	floor;
	int		exit_i;
	int		exit_j;
	int		trigger;
	int		player_up;
	int		player_down;
	int		player_right;
	int		player_left;
	int		mob_up;
	int		mob_down;
	int		mob_right;
	int		mob_left;
	int		width;
	int		height;
	char	**map;
	int		move;
	int		end;
	char	*map_name;
	int		size_line;
}	t_data;

int		main(int argc, char **argv);
void	init(t_data *data);
int		init_2(t_data *data);

int		init_image(t_data *data);
int		init_image2(t_data *data, t_img *img, char *name);
int		init_image3(t_data *data);

char	**parse_map(t_data *data);
int		count_line(t_data *data);
char	**init_str_map(t_data *data, int size_line);

int		check_map_name(char *argv);
int		check_map_size(t_data *data);
void	size_map(char **map, int size_line, t_data *data);

void	hide_the_exit(t_data *data);
void	hide_multiple_players(t_data *data);
void	hide_multiple_mob(t_data *data);

int		check_map_elem(t_data *data);
int		check_map_elem2(t_data *data, char elem);
int		check_map_wall(t_data *data);

int		display(t_data *data);
int		display_image(t_data *data, char c, int j, int i);
void	display_player_image(t_data *data, int i, int j);
void	display_mob_image(t_data *data, int i, int j);
int		collect_or_not(t_data *data);

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

void	move_mob(t_data *data);
void	move_mob_up(t_data *data);
void	move_mob_left(t_data *data);
void	move_mob_down(t_data *data);
void	move_mob_right(t_data *data);

void	where_is_my_player(char **map, int *i, int *j);
void	where_is_my_mob(char **map, int *i, int *j);

void	animation_move(t_data *data, int direction);
void	animation_mob_move(t_data *data, int direction);

int		h_keypress(int key, t_data *data);
int		button_cross(t_data *data);
void	destroy_str(char **map);
void	destroy_all(t_data *data);
void	destroy_player_and_mob(t_data *data);

#endif 