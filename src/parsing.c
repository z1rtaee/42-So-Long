/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:08:47 by bpires-r          #+#    #+#             */
 /*   Updated: 2025/04/08 19:14:00 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_map_name(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '.')
		i++;
	if (ft_strcmp(&map[i], ".ber"))
		return (false);
	return (true);
}

void	read_map(char *map, t_solong *data)
{
	int		fd;
	char	*line;
	size_t	row_len;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Error", data, NULL, fd);
	line = ft_strtrim(get_next_line(fd), "\n");
	if (!line)
		exit_error("Error", data, line, fd);
	row_len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
		data->map.row_count++;
		if (line && ft_strlen(line) != row_len)
			exit_error("Error", data, line, fd);
	}
	create_map(map, data->map.row_count, data);
	close(fd);
}

void	check_characters(t_solong *data)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	count_characters(data, &p, &e, &data->map.c_count);
	if (p != 1)
		exit_error("Error: Map must contain exactly one player (P).", data, NULL, -1);
	if (e != 1)
		exit_error("Error: Map must contain exactly one exit (E).", data, NULL, -1);
	if (data->map.c_count < 1)
		exit_error("Error: Map must contain at least one collectible (C).",
			data, NULL, -1);
}

void	check_walls(t_solong *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->map.col_count = ft_strlen(data->map.map[0]);
	while (y < data->map.col_count)
	{
		if (data->map.map[0][y] != '1' 
			   || data->map.map[data->map.row_count - 1][y] != '1')
			exit_error("row is not closed.", data, NULL, -1);
		y++;
	}
	while (x < data->map.row_count)
	{
		if (data->map.map[x][0] != '1' 
			   || data->map.map[x][data->map.col_count - 1] != '1')
			exit_error("collumn is not closed.", data, NULL, -1);
		x++;
	}
}

void	is_solvable(t_solong *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	cpy_map(&data->map);
	flood_fill(data->map.map_cpy, data->player.pos_x / 64, data->player.pos_y / 64);
	x = 0;
	while (data->map.map_cpy[x])
	{
		y = 0;
		while (data->map.map_cpy[x][y])
		{
			if (data->map.map_cpy[x][y] != '1' && data->map.map_cpy[x][y] != 'F')
				exit_error("Map is not solvable", data, NULL, -1);
			y++;
		}
		x++;
	}
}