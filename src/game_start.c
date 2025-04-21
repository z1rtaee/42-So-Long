/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:22:30 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/19 19:52:00 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	data_init(t_solong *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "So Long");
	data->final_screen.image = mlx_new_image(data->mlx, data->map.col_count * 64, data->map.row_count * 64);
	data->final_screen.width = data->map.col_count * 64;
	data->final_screen.height = data->map.row_count * 64;
	data->final_screen.data = mlx_get_data_addr(data->final_screen.image, &data->final_screen.bpp, &data->final_screen.size_line, &data->final_screen.type);
	
	data->view_x = 0;
	data->view_y = 0;
}

void	game_start(t_solong *data)
{
	load_map(data);
	load_collectibles(data);
	load_player(data);
	draw_tiles(data);
	mlx_put_image_to_window(data->mlx, data->window, data->final_screen.image, -data->view_x, -data->view_y);
	mlx_hook(data->window, 2, 1L<<0, key_pressed, data);
    mlx_hook(data->window, 3, 1L<<1, key_released, data);
	mlx_hook(data->window, 17, 0, x_window, data);
	mlx_loop_hook(data->mlx, render_game, data);
	mlx_loop(data->mlx);
}
