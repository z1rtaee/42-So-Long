/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:40:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 18:25:15 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	copy_map(char *map, int rows, t_solong *data)
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
		exit_error("Error", NULL, fd);
	line = get_next_line(fd);
	while (line)
	{
		trim = ft_strtrim(line, "\n");
		map_dup[i] = trim;
		free(trim);
		line = get_next_line(fd);
		i++;
	}
	map_dup[i] = NULL;
	data->map.map = map_dup;
	free(map_dup);
	close(fd);
}

void	count_characters(char *map, int *p, int *e, int *c)
{
	int		i;
	int		fd;
	char	*row;

	fd = open(map, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		i = 0;
		while (row[i])
		{
			if (row[i] == 'P')
				(*p)++;
			else if (row[i] == 'E')
				(*e)++;
			else if (row[i] == 'C')
				(*c)++;
			else if (row[i] != '0' && row[i] != '1' && row[i] != '\n')
				exit_error("Error: Invalid character in map.", row, fd);
			i++;
		}
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
}

// void	check_rows(t_solong *data)
// {
// 	int	y;

// 	y = 0;
// 	while (data->map.map[0][y])
// 	{
// 		if (data->map.map[0][y] != '1')
// 			exit_error("Top row is not closed.", NULL, -1);
// 		y++;
// 	}
// 	y = 0;
// 	while (data->map.map[data->map.row_count - 1][y])
// 	{
// 		if (data->map.map[data->map.row_count - 1][y] != '1')
// 			exit_error("Bottom row is not closed.", NULL, -1);
// 		y++;
// 	}
// }

// void	check_cols(char **map, t_solong *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	data->map.col_count = ft_strlen(map[0]);
// 	while (map[0][y])
// 	{
// 		if (map[0][y] != 1)
// 			exit_error("Top row is not closed.", NULL, -1);
// 		y++;
// 	}
// 	y = 0;
// 	while (map[data->map.row_count][y])
// 	{
// 		if (map[data->map.row_count][y] != 1)
// 			exit_error("Bottom row is not closed.", NULL, -1);
// 		y++;
// 	}
// }
