/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:40:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/23 01:26:47 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_map(char *map, int rows, t_solong *data)
{
	char	**map_dup;
	char	*line;
	char	*trim;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	map_dup = malloc(sizeof(char *) * (rows + 1));
	if (!map_dup)
		exit_error("Error", data, NULL, fd);
	line = get_next_line(fd);
	while (line)
	{
		trim = ft_strtrim(line, "\n");
		map_dup[i] = ft_strdup(trim);
		free(trim);
		line = get_next_line(fd);
		i++;
	}
	map_dup[i] = NULL;
	data->map.map = map_dup;
	close(fd);
}

void	cpy_map(t_map *map)
{
	int	x;

	x = -1;
	map->map_cpy = malloc(sizeof(char *) * (map->row_count + 1));
	while (map->map[++x])
		map->map_cpy[x] = ft_strdup(map->map[x]);
	map->map_cpy[x] = NULL;
}

void	count_characters(t_solong *data, int *p, int *e, int *c)
{
	int		y;
	int		x;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == 'P')
			{
				data->player.pos_x = x * 64;
				data->player.pos_y = y * 64;
				data->player.farthest_x = data->player.pos_x + 64 - 1;
				data->player.farthest_y = data->player.pos_y + 64 - 1;
				//printf("player's x-axis position -> %i\n player's y-axis position -> %i\n", data->player.pos_x, data->player.pos_y);
				(*p)++;
			}
			else if (data->map.map[x][y] == 'E')
				(*e)++;
			else if (data->map.map[x][y] == 'C')
				(*c)++;
			else if (data->map.map[x][y] != '0' && data->map.map[x][y] != '1' && data->map.map[x][y] != 'F' && data->map.map[x][y] != '\n')
				exit_error("Error: Invalid character in map.", data, NULL, -1);
			y++;
		}
		x++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1')
		return ;
	map[x][y] = '1';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
