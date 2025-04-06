#ifndef SO_LONG_H
# define SO_LONG_H

# include "../complete_lib/42_Libft/libft.h"
# include "../complete_lib/42_GNL/get_next_line_bonus.h"
# include "../complete_lib/42_Printf/ft_printf.h"
# include "../complete_lib/minilibx-linux/mlx.h"

typedef struct	s_solong {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_solong;

bool	check_map_name(char *map);

void	read_map(char *map);

void	exit_error(char *error_message);

#endif