/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:52 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 18:11:13 by bpires-r         ###   ########.fr       */
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
	int		row_count;
	int		col_count;
	int		c_count;

}			t_map;

typedef struct s_solong
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}			t_solong;

bool		check_map_name(char *map);

void		copy_map(char *map, int rows, t_solong *data);

void		alloc_rows(t_solong *data, int fd);

void		read_map(char *map, t_solong *data);

void		count_characters(char *map, int *p, int *e, int *c);

void		check_characters(char *map, t_solong data);

void		check_rows(t_solong *data);

void		exit_error(char *error_message, char *str, int fd);

#endif
