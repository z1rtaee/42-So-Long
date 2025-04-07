/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:40:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 01:25:03 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_characters(char *map, int *p, int *e, int *c)
{
	int	i;
	int	fd;
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
