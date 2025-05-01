/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:52 by bpires-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:46:28 by bpires-r         ###   ########.fr       */
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
# define PLAYER_SPEED 4
# define FPS 60
# define FRAME_TIME 2

typedef struct s_player_tiles
{
	t_img	up_0[3];
	t_img	down_0[3];
	t_img	left_0[3];
	t_img	right_0[3];
	t_img	up_1[3];
	t_img	down_1[3];
	t_img	left_1[3];
	t_img	right_1[3];
}				t_player_tiles;

typedef struct s_tiles
{
	t_player_tiles	player;
	t_img			c1[3];
	t_img			exit;
	t_img			enemy;
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
	int				pos_y;
	int				pos_x;
	int				farthest_x;
	int				farthest_y;
	int				move_count;
	struct timeval	last_frame;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
}				t_keys;

typedef struct s_menu
{
	t_img	credits_menu;
	t_img	play_menu;
	t_img	p_select_0;
	t_img	p_select_1;
	t_img	credits;
}				t_menu;

typedef enum e_status
{
	MENU,
	PLAYER_SELECT,
	GAME,
	CREDITS,
}				t_status;

typedef struct s_solong
{
	void		*mlx;
	void		*window;
	int			view_x;
	int			view_y;
	int			menu_choice;
	int			player_choice;
	int			frame;
	t_status	status;
	t_img		screen;
	t_tiles		tile_frame;
	t_map		map;
	t_player	player;
	t_keys		keys;
	t_menu		menu;
}			t_solong;

/// @brief Init : Initializes non related to mlx data from the struct
/// @param data Main struct that gives access to all data
void			init_so_long(t_solong *data);
//Init : Initializes data that is related to mlx work only after
// parsing was checked and the game is playable
void			data_init(t_solong *data);

//Exit and Free everything in case of error or in game end.
void			exit_error(char *error_message,
					t_solong *data, char *str, int fd);
void			exit_game(char *end_game, t_solong *data);
int				x_window(t_solong *data);

//Frees and Image Destroyers
void			free_all(t_solong *data, char *str);
void			destroy_image(t_solong *data);

//Map utils for parse
void			create_map(char *map, int rows, t_solong *data);
void			cpy_map(t_map *map);
void			count_characters(t_solong *data, int *p, int *e, int *c);
void			flood_fill(char **map, int x, int y);
void			init_player(t_solong *data, int x, int y);

//Parsing
bool			check_map_name(char *map);
void			read_map(char *map, t_solong *data);
void			check_characters(t_solong *data);
void			check_walls(t_solong *data);
void			is_solvable(t_solong *data);

//Game

//Game start
void			game_start(t_solong *data);

//MLX Image Loading
//Map Loading
void			load_map(t_solong *data);
//Player Loading
void			load_player_0(t_solong *data);
void			load_player_1(t_solong *data);

//Draw Map and All
void			draw_screen(t_solong *data);
void			draw_tiles(t_solong *data, int x, int y);
void			draw_player_0(t_solong *data);
void			draw_player_1(t_solong *data);
void			pixel_put(t_img *img, int x, int y, int color);
void			put_img_to_screen(t_img *screen, t_img img,
					int screen_x, int screen_y);

//Keys Handle
int				key_released(int keycode, t_solong *data);
int				key_pressed(int keycode, t_solong *data);
int				handle_game_input(int keycode, t_solong *data);
int				handle_menu_input(int keycode, t_solong *data);
int				handle_p_select_input(int keycode, t_solong *data);

//Game Render
int				render_game(t_solong *data);
void			render_menu(t_solong *data);
void			render_p_select(t_solong *data);
void			render_gameplay(t_solong *data);

//Delta time
double			get_delta_time(void);

//Player and Screen Movement
int				check_collision(t_solong *data, int key_pressed);
void			player_movement(t_solong *data);
void			adjust_view(t_solong *data);
void			handle_scroll(t_solong *data);
void			update_map(t_solong *data);

//Check collisions
int				check_collision(t_solong *data, int key_pressed);
int				check_exit_collision(t_solong *data, int key_pressed);

#endif
