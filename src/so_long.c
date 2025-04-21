/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:13:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/19 22:27:16 by bpires-r         ###   ########.fr       */
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
	data->map.c_collected = 0;
	data->map.row_count = 0;
	data->map.col_count = 0;
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->menu_choice = 0;
	data->player_choice = 0;
	data->status = MENU;
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
	check_walls(&data);
	is_solvable(&data);
	data_init(&data);
	game_start(&data);
}
