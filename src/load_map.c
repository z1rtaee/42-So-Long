/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:41:11 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 18:40:55 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_collectibles_enemy(t_solong *data)
{
	data->tile_frame.c1[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/c1_1.xpm", &data->tile_frame.c1[0].width,
			&data->tile_frame.c1[0].height);
	data->tile_frame.c1[0].data
		= mlx_get_data_addr(data->tile_frame.c1[0].image,
			&data->tile_frame.c1[0].bpp, &data->tile_frame.c1[0].size_line,
			&data->tile_frame.c1[0].type);
	data->tile_frame.enemy.image = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy.xpm", &data->tile_frame.enemy.width,
			&data->tile_frame.enemy.height);
	data->tile_frame.enemy.data
		= mlx_get_data_addr(data->tile_frame.enemy.image,
			&data->tile_frame.enemy.bpp, &data->tile_frame.enemy.size_line,
			&data->tile_frame.enemy.type);
}

static void	load_menu_credits(t_solong *data)
{
	data->menu.credits_menu.image = mlx_xpm_file_to_image(data->mlx,
			"textures/credits_menu.xpm", &data->menu.credits_menu.width,
			&data->menu.credits_menu.height);
	data->menu.play_menu.image = mlx_xpm_file_to_image(data->mlx,
			"textures/play_menu.xpm", &data->menu.play_menu.width,
			&data->menu.play_menu.height);
	data->menu.credits_menu.data
		= mlx_get_data_addr(data->menu.credits_menu.image,
			&data->menu.credits_menu.bpp, &data->menu.credits_menu.size_line,
			&data->menu.credits_menu.type);
	data->menu.play_menu.data = mlx_get_data_addr(data->menu.play_menu.image,
			&data->menu.play_menu.bpp, &data->menu.play_menu.size_line,
			&data->menu.play_menu.type);
	data->menu.credits.image = mlx_xpm_file_to_image(data->mlx,
			"textures/credits.xpm", &data->menu.credits.width,
			&data->menu.credits.height);
	data->menu.credits.data = mlx_get_data_addr(data->menu.credits.image,
			&data->menu.credits.bpp, &data->menu.credits.size_line,
			&data->menu.credits.type);
}

static void	load_select(t_solong *data)
{
	data->menu.p_select_0.image = mlx_xpm_file_to_image(data->mlx,
			"textures/p_select_0.xpm", &data->menu.p_select_0.width,
			&data->menu.p_select_0.height);
	data->menu.p_select_1.image = mlx_xpm_file_to_image(data->mlx,
			"textures/p_select_1.xpm", &data->menu.p_select_1.width,
			&data->menu.p_select_1.height);
	data->menu.p_select_0.data = mlx_get_data_addr(data->menu.p_select_0.image,
			&data->menu.p_select_0.bpp, &data->menu.p_select_0.size_line,
			&data->menu.p_select_0.type);
	data->menu.p_select_1.data = mlx_get_data_addr(data->menu.p_select_1.image,
			&data->menu.p_select_1.bpp, &data->menu.p_select_1.size_line,
			&data->menu.p_select_1.type);
}

void	load_map(t_solong *data)
{
	data->tile_frame.floor.image = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &data->tile_frame.floor.width,
			&data->tile_frame.floor.height);
	data->tile_frame.floor.data
		= mlx_get_data_addr(data->tile_frame.floor.image,
			&data->tile_frame.floor.bpp, &data->tile_frame.floor.size_line,
			&data->tile_frame.floor.type);
	data->tile_frame.wall.image = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &data->tile_frame.wall.width,
			&data->tile_frame.wall.height);
	data->tile_frame.wall.data = mlx_get_data_addr(data->tile_frame.wall.image,
			&data->tile_frame.wall.bpp, &data->tile_frame.wall.size_line,
			&data->tile_frame.wall.type);
	data->tile_frame.exit.image = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &data->tile_frame.exit.width,
			&data->tile_frame.exit.height);
	data->tile_frame.exit.data
		= mlx_get_data_addr(data->tile_frame.exit.image,
			&data->tile_frame.exit.bpp, &data->tile_frame.exit.size_line,
			&data->tile_frame.exit.type);
	load_collectibles_enemy(data);
	load_select(data);
	load_menu_credits(data);
}
