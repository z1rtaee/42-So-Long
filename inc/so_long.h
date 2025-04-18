/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:52 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/18 22:16:35 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../complete_lib/42_GNL/get_next_line_bonus.h"
# include "../complete_lib/42_Libft/libft.h"
# include "../complete_lib/42_Printf/ft_printf.h"
# include "../complete_lib/minilibx-linux/mlx.h"
# include "../complete_lib/minilibx-linux/mlx_int.h"

# define WIDTH 1920
# define HEIGHT 1080
# define PLAYER_SPEED 20

typedef struct s_c4_tiles
{
	t_img	frame_1;
	t_img	frame_2;
	t_img	frame_3;
	t_img	frame_4;
}				t_c4_tiles;

typedef struct s_c3_tiles
{
	t_img	frame_1;
	t_img	frame_2;
	t_img	frame_3;
	t_img	frame_4;
}				t_c3_tiles;

typedef struct s_c2_tiles
{
	t_img	frame_1;
	t_img	frame_2;
	t_img	frame_3;
	t_img	frame_4;
}				t_c2_tiles;

typedef struct s_c1_tiles
{
	t_img	frame_1;
	t_img	frame_2;
	t_img	frame_3;
	t_img	frame_4;
}				t_c1_tiles;

typedef struct s_player_tiles
{
	t_img	f_stand;
	t_img	l_walk_1;
	t_img	l_walk_2;
	t_img	r_walk_1;
	t_img	r_walk_2;
	t_img	u_walk_1;
	t_img	u_walk_2;
	t_img	d_walk_1;
	t_img	d_walk_2;
}				t_player_tiles;

typedef struct s_tiles
{
	t_player_tiles 	player;
	t_c1_tiles		c1;
	t_c2_tiles		c2;
	t_c3_tiles		c3;
	t_c4_tiles		c4;
	t_img			open_e;
	t_img			closed_e;
	t_img			wall;
	t_img			floor;
}				t_tiles;

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		row_count;
	int		col_count;
	int		c_count;
	int		c_collected;
}			t_map;

typedef struct s_player
{
	int	pos_y;
	int	pos_x;
	int farthest_x;
	int farthest_y;
}				t_player;

typedef struct s_keys
{
	int w;
	int a;
	int s;
	int d;
}				t_keys;

typedef struct s_solong
{
	void		*mlx;
	void		*window;
	int			view_x;
	int			view_y;
	t_img		final_screen;
	t_img		frame_buffer;
	t_tiles		tile_frame;
	t_map		map;
	t_player	player;
	t_keys		keys;
}			t_solong;

bool		check_map_name(char *map);

void		create_map(char *map, int rows, t_solong *data);

void		read_map(char *map, t_solong *data);

void		count_characters(t_solong *data, int *p, int *e, int *c);

void		check_characters(t_solong *data);

void		check_walls(t_solong *data);

void		cpy_map(t_map *map);

void		flood_fill(char **map, int x, int y);

void		is_solvable(t_solong *data);

void		exit_error(char *error_message, t_solong *data, char *str, int fd);

void		data_init(t_solong *data);

void		load_player(t_solong *data);

void		load_map(t_solong *data);

void		load_collectibles(t_solong *data);

void		draw_tiles(t_solong *data);

void		draw_rendered(t_solong *data);

void		get_adr_collectibles(t_solong *data);

void		pixel_put(t_img *img, int x, int y, int color);

void		put_img_to_screen(t_img *screen, t_img img, int screen_x, int screen_y);

int 		key_handle(int keycode, t_solong *data);

void		handle_scroll(t_solong *data);

void		exit_game(char *end_game, t_solong *data);

void		adjust_view(t_solong *data);

void		update_map(t_solong *data, int key_pressed);

int			check_collision(t_solong *data, int key_pressed);

int			x_window(t_solong *data);

int			render_game(t_solong *data);

void		game_start(t_solong *data);

int			key_pressed(int keycode, t_solong *data);

int			key_released(int keycode, t_solong *data);

void		player_movement(t_solong *data);

#endif
