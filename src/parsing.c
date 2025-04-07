/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:08:47 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 18:01:29 by bpires-r         ###   ########.fr       */
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
		exit_error("Error", NULL, fd);
	line = ft_strtrim(get_next_line(fd), "\n");
	if (!line)
		exit_error("Error", line, fd);
	row_len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
		data->map.row_count++;
		if (line && ft_strlen(line) != row_len)
			exit_error("Error", line, fd);
	}
	copy_map(map, data->map.row_count, data);
	close(fd);
}

void	check_characters(char *map, t_solong data)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_characters(map, &p, &e, &c);
	data.map.c_count = c;
	if (p != 1)
		exit_error("Error: Map must contain exactly one player (P).", NULL, -1);
	if (e != 1)
		exit_error("Error: Map must contain exactly one exit (E).", NULL, -1);
	if (c < 1)
		exit_error("Error: Map must contain at least one collectible (C).",
			NULL, -1);
}


