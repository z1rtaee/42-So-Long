/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:52 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/08 19:41:49 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../complete_lib/42_GNL/get_next_line_bonus.h"
# include "../complete_lib/42_Libft/libft.h"
# include "../complete_lib/42_Printf/ft_printf.h"
# include "../complete_lib/minilibx-linux/mlx.h"

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		row_count;
	int		col_count;
	int		c_count;

}			t_map;

typedef struct s_player
{
	int	pos_y;
	int	pos_x;
}				t_player;

typedef struct s_solong
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		map;
	t_player	player;
}			t_solong;

bool		check_map_name(char *map);

void		create_map(char *map, int rows, t_solong *data);

void		alloc_rows(t_solong *data, int fd);

void		read_map(char *map, t_solong *data);

void		count_characters(t_solong *data, int *p, int *e, int *c);

void		check_characters(t_solong *data);

void		check_walls(t_solong *data);

void		cpy_map(t_map *map);

void		flood_fill(char **map, int x, int y);

void		is_solvable(t_solong *data);

void		exit_error(char *error_message, t_solong *data, char *str, int fd);

#endif
