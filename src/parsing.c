/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:08:47 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:46:56 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_map_name(char *map)
{
	int	i;

	i = 0;
	while(map[i] && map[i] != '.')
		i++;
	if (!map[i] && ft_strcmp(&map[i], ".ber"))
		return (false);
	return(true);
}

void	read_map(char *map)
{
	int		fd;
	char	*row;
	size_t		row_len;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Unsuccessful map opening.");
	row = ft_strtrim(get_next_line(fd), "\n");
	row_len = ft_strlen(row);
	if (!row)
		exit_error("No map to read.");
	while (row)
	{
		free(row);
		row = ft_strtrim(get_next_line(fd), "\n");
		if (row && ft_strlen(row) != row_len)
		{
			free(row);
			exit_error("Map should be rectangular");
		}

	}
}
