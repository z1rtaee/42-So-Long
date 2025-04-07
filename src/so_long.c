/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:13:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 19:56:43 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_so_long(t_solong *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->map.map = NULL;
	data->map.c_count = 0;
	data->map.row_count = 0;
}

int	main(int argc, char **argv)
{
	t_solong	data;

	if (argc != 2)
		exit_error("Error", NULL, -1);
	if (!check_map_name(argv[1]))
		exit_error("Error", NULL, -1);
	init_so_long(&data);
	read_map(argv[1], &data);
	check_characters(argv[1], data);
	check_rows(&data);
}
