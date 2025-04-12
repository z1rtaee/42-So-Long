/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:13:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/10 22:37:38 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_so_long(t_solong *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->map.map = NULL;
	data->map.map_cpy = 0;
	data->map.c_count = 0;
	data->map.row_count = 0;
	data->map.col_count = 0;
}

int	main(int argc, char **argv)
{
	t_solong	data;

	init_so_long(&data);
	if (argc != 2)
		exit_error("Error", &data, NULL, -1);
	if (!check_map_name(argv[1]))
		exit_error("Error", &data, NULL, -1);
	read_map(argv[1], &data);
	check_characters(&data);
	printf("wow\n");
	check_walls(&data);
	is_solvable(&data);
	printf("ah\n");
	data_init(&data);
	free_ar((void **)data.map.map_cpy);
	free_ar((void **)data.map.map);
}
