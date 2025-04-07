#ifndef SO_LONG_H
# define SO_LONG_H

# include "../complete_lib/42_Libft/libft.h"
# include "../complete_lib/42_GNL/get_next_line_bonus.h"
# include "../complete_lib/42_Printf/ft_printf.h"
# include "../complete_lib/minilibx-linux/mlx.h"

typedef struct	s_map
{
	char	**map;
	int		c_count;
}				t_map;

typedef struct	s_solong
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}				t_solong;

bool	check_map_name(char *map);

void	read_map(char *map);

void	count_characters(char *map, int *p, int *e, int *c);

void	check_characters(char *map, t_solong data);

void	exit_error(char *error_message, char *str, int fd);

#endif