/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:41:11 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/23 01:25:23 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_player_1(t_solong *data)
{
	data->tile_frame.player.down_1[0].image = mlx_xpm_file_to_image(data->mlx, "textures/1_down_0.xpm", &data->tile_frame.player.down_1[0].width, &data->tile_frame.player.down_1[0].height);
	data->tile_frame.player.down_1[1].image = mlx_xpm_file_to_image(data->mlx, "textures/1_down_1.xpm", &data->tile_frame.player.down_1[1].width, &data->tile_frame.player.down_1[1].height);
	data->tile_frame.player.down_1[2].image = mlx_xpm_file_to_image(data->mlx, "textures/1_down_2.xpm", &data->tile_frame.player.down_1[2].width, &data->tile_frame.player.down_1[2].height);
	data->tile_frame.player.down_1[0].data = mlx_get_data_addr(data->tile_frame.player.down_1[0].image, &data->tile_frame.player.down_1[0].bpp, &data->tile_frame.player.down_1[0].size_line, &data->tile_frame.player.down_1[0].type);
	data->tile_frame.player.down_1[1].data = mlx_get_data_addr(data->tile_frame.player.down_1[1].image, &data->tile_frame.player.down_1[1].bpp, &data->tile_frame.player.down_1[1].size_line, &data->tile_frame.player.down_1[1].type);
	data->tile_frame.player.down_1[2].data = mlx_get_data_addr(data->tile_frame.player.down_1[2].image, &data->tile_frame.player.down_1[2].bpp, &data->tile_frame.player.down_1[2].size_line, &data->tile_frame.player.down_1[2].type);
	data->tile_frame.player.up_1[0].image = mlx_xpm_file_to_image(data->mlx, "textures/1_up_0.xpm", &data->tile_frame.player.up_1[0].width, &data->tile_frame.player.up_1[0].height);
	data->tile_frame.player.up_1[1].image = mlx_xpm_file_to_image(data->mlx, "textures/1_up_1.xpm", &data->tile_frame.player.up_1[1].width, &data->tile_frame.player.up_1[1].height);
	data->tile_frame.player.up_1[2].image = mlx_xpm_file_to_image(data->mlx, "textures/1_up_2.xpm", &data->tile_frame.player.up_1[2].width, &data->tile_frame.player.up_1[2].height);
	data->tile_frame.player.up_1[0].data = mlx_get_data_addr(data->tile_frame.player.up_1[0].image, &data->tile_frame.player.up_1[0].bpp, &data->tile_frame.player.up_1[0].size_line, &data->tile_frame.player.up_1[0].type);
	data->tile_frame.player.up_1[1].data = mlx_get_data_addr(data->tile_frame.player.up_1[1].image, &data->tile_frame.player.up_1[1].bpp, &data->tile_frame.player.up_1[1].size_line, &data->tile_frame.player.up_1[1].type);
	data->tile_frame.player.up_1[2].data = mlx_get_data_addr(data->tile_frame.player.up_1[2].image, &data->tile_frame.player.up_1[2].bpp, &data->tile_frame.player.up_1[2].size_line, &data->tile_frame.player.up_1[2].type);
	data->tile_frame.player.left_1[0].image = mlx_xpm_file_to_image(data->mlx, "textures/1_left_0.xpm", &data->tile_frame.player.left_1[0].width, &data->tile_frame.player.left_1[0].height);
	data->tile_frame.player.left_1[1].image = mlx_xpm_file_to_image(data->mlx, "textures/1_left_1.xpm", &data->tile_frame.player.left_1[1].width, &data->tile_frame.player.left_1[1].height);
	data->tile_frame.player.left_1[2].image = mlx_xpm_file_to_image(data->mlx, "textures/1_left_2.xpm", &data->tile_frame.player.left_1[2].width, &data->tile_frame.player.left_1[2].height);
	data->tile_frame.player.left_1[0].data = mlx_get_data_addr(data->tile_frame.player.left_1[0].image, &data->tile_frame.player.left_1[0].bpp, &data->tile_frame.player.left_1[0].size_line, &data->tile_frame.player.left_1[0].type);
	data->tile_frame.player.left_1[1].data = mlx_get_data_addr(data->tile_frame.player.left_1[1].image, &data->tile_frame.player.left_1[1].bpp, &data->tile_frame.player.left_1[1].size_line, &data->tile_frame.player.left_1[1].type);
	data->tile_frame.player.left_1[2].data = mlx_get_data_addr(data->tile_frame.player.left_1[2].image, &data->tile_frame.player.left_1[2].bpp, &data->tile_frame.player.left_1[2].size_line, &data->tile_frame.player.left_1[2].type);
	data->tile_frame.player.right_1[0].image = mlx_xpm_file_to_image(data->mlx, "textures/1_right_0.xpm", &data->tile_frame.player.right_1[0].width, &data->tile_frame.player.right_1[0].height);
	data->tile_frame.player.right_1[1].image = mlx_xpm_file_to_image(data->mlx, "textures/1_right_1.xpm", &data->tile_frame.player.right_1[1].width, &data->tile_frame.player.right_1[1].height);
	data->tile_frame.player.right_1[2].image = mlx_xpm_file_to_image(data->mlx, "textures/1_right_2.xpm", &data->tile_frame.player.right_1[2].width, &data->tile_frame.player.right_1[2].height);
	data->tile_frame.player.right_1[0].data = mlx_get_data_addr(data->tile_frame.player.right_1[0].image, &data->tile_frame.player.right_1[0].bpp, &data->tile_frame.player.right_1[0].size_line, &data->tile_frame.player.right_1[0].type);
	data->tile_frame.player.right_1[1].data = mlx_get_data_addr(data->tile_frame.player.right_1[1].image, &data->tile_frame.player.right_1[1].bpp, &data->tile_frame.player.right_1[1].size_line, &data->tile_frame.player.right_1[1].type);
	data->tile_frame.player.right_1[2].data = mlx_get_data_addr(data->tile_frame.player.right_1[2].image, &data->tile_frame.player.right_1[2].bpp, &data->tile_frame.player.right_1[2].size_line, &data->tile_frame.player.right_1[2].type);
}

void	load_player_0(t_solong *data)
{
	data->tile_frame.player.down_0[0].image = mlx_xpm_file_to_image(data->mlx, "textures/down_0.xpm", &data->tile_frame.player.down_0[0].width, &data->tile_frame.player.down_0[0].height);
	data->tile_frame.player.down_0[1].image = mlx_xpm_file_to_image(data->mlx, "textures/down_1.xpm", &data->tile_frame.player.down_0[1].width, &data->tile_frame.player.down_0[1].height);
	data->tile_frame.player.down_0[2].image = mlx_xpm_file_to_image(data->mlx, "textures/down_2.xpm", &data->tile_frame.player.down_0[2].width, &data->tile_frame.player.down_0[2].height);
	data->tile_frame.player.down_0[0].data = mlx_get_data_addr(data->tile_frame.player.down_0[0].image, &data->tile_frame.player.down_0[0].bpp, &data->tile_frame.player.down_0[0].size_line, &data->tile_frame.player.down_0[0].type);
	data->tile_frame.player.down_0[1].data = mlx_get_data_addr(data->tile_frame.player.down_0[1].image, &data->tile_frame.player.down_0[1].bpp, &data->tile_frame.player.down_0[1].size_line, &data->tile_frame.player.down_0[1].type);
	data->tile_frame.player.down_0[2].data = mlx_get_data_addr(data->tile_frame.player.down_0[2].image, &data->tile_frame.player.down_0[2].bpp, &data->tile_frame.player.down_0[2].size_line, &data->tile_frame.player.down_0[2].type);
	data->tile_frame.player.up_0[0].image = mlx_xpm_file_to_image(data->mlx, "textures/up_0.xpm", &data->tile_frame.player.up_0[0].width, &data->tile_frame.player.up_0[0].height);
	data->tile_frame.player.up_0[1].image = mlx_xpm_file_to_image(data->mlx, "textures/up_1.xpm", &data->tile_frame.player.up_0[1].width, &data->tile_frame.player.up_0[1].height);
	data->tile_frame.player.up_0[2].image = mlx_xpm_file_to_image(data->mlx, "textures/up_2.xpm", &data->tile_frame.player.up_0[2].width, &data->tile_frame.player.up_0[2].height);
	data->tile_frame.player.up_0[0].data = mlx_get_data_addr(data->tile_frame.player.up_0[0].image, &data->tile_frame.player.up_0[0].bpp, &data->tile_frame.player.up_0[0].size_line, &data->tile_frame.player.up_0[0].type);
	data->tile_frame.player.up_0[1].data = mlx_get_data_addr(data->tile_frame.player.up_0[1].image, &data->tile_frame.player.up_0[1].bpp, &data->tile_frame.player.up_0[1].size_line, &data->tile_frame.player.up_0[1].type);
	data->tile_frame.player.up_0[2].data = mlx_get_data_addr(data->tile_frame.player.up_0[2].image, &data->tile_frame.player.up_0[2].bpp, &data->tile_frame.player.up_0[2].size_line, &data->tile_frame.player.up_0[2].type);
	data->tile_frame.player.left_0[0].image = mlx_xpm_file_to_image(data->mlx, "textures/left_0.xpm", &data->tile_frame.player.left_0[0].width, &data->tile_frame.player.left_0[0].height);
	data->tile_frame.player.left_0[1].image = mlx_xpm_file_to_image(data->mlx, "textures/left_1.xpm", &data->tile_frame.player.left_0[1].width, &data->tile_frame.player.left_0[1].height);
	data->tile_frame.player.left_0[2].image = mlx_xpm_file_to_image(data->mlx, "textures/left_2.xpm", &data->tile_frame.player.left_0[2].width, &data->tile_frame.player.left_0[2].height);
	data->tile_frame.player.left_0[0].data = mlx_get_data_addr(data->tile_frame.player.left_0[0].image, &data->tile_frame.player.left_0[0].bpp, &data->tile_frame.player.left_0[0].size_line, &data->tile_frame.player.left_0[0].type);
	data->tile_frame.player.left_0[1].data = mlx_get_data_addr(data->tile_frame.player.left_0[1].image, &data->tile_frame.player.left_0[1].bpp, &data->tile_frame.player.left_0[1].size_line, &data->tile_frame.player.left_0[1].type);
	data->tile_frame.player.left_0[2].data = mlx_get_data_addr(data->tile_frame.player.left_0[2].image, &data->tile_frame.player.left_0[2].bpp, &data->tile_frame.player.left_0[2].size_line, &data->tile_frame.player.left_0[2].type);
	data->tile_frame.player.right_0[0].image = mlx_xpm_file_to_image(data->mlx, "textures/right_0.xpm", &data->tile_frame.player.right_0[0].width, &data->tile_frame.player.right_0[0].height);
	data->tile_frame.player.right_0[1].image = mlx_xpm_file_to_image(data->mlx, "textures/right_1.xpm", &data->tile_frame.player.right_0[1].width, &data->tile_frame.player.right_0[1].height);
	data->tile_frame.player.right_0[2].image = mlx_xpm_file_to_image(data->mlx, "textures/right_2.xpm", &data->tile_frame.player.right_0[2].width, &data->tile_frame.player.right_0[2].height);
	data->tile_frame.player.right_0[0].data = mlx_get_data_addr(data->tile_frame.player.right_0[0].image, &data->tile_frame.player.right_0[0].bpp, &data->tile_frame.player.right_0[0].size_line, &data->tile_frame.player.right_0[0].type);
	data->tile_frame.player.right_0[1].data = mlx_get_data_addr(data->tile_frame.player.right_0[1].image, &data->tile_frame.player.right_0[1].bpp, &data->tile_frame.player.right_0[1].size_line, &data->tile_frame.player.right_0[1].type);
	data->tile_frame.player.right_0[2].data = mlx_get_data_addr(data->tile_frame.player.right_0[2].image, &data->tile_frame.player.right_0[2].bpp, &data->tile_frame.player.right_0[2].size_line, &data->tile_frame.player.right_0[2].type);
}

void	load_map(t_solong *data)
{
	data->tile_frame.wall.image = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &data->tile_frame.wall.width, &data->tile_frame.wall.height);
    data->tile_frame.floor.image = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &data->tile_frame.floor.width, &data->tile_frame.floor.height);
	//data->tile_frame.open_e.image = mlx_xpm_file_to_image(data->mlx, "textures/open_e.xpm", &data->tile_frame.open_e.width, &data->tile_frame.open_e.height);
	//data->tile_frame.closed_e.image =mlx_xpm_file_to_image(data->mlx, "textures/l_walk_1.xpm", &data->tile_frame.closed_e.width, &data->tile_frame.closed_e.height);
	data->tile_frame.wall.data = mlx_get_data_addr(data->tile_frame.wall.image, &data->tile_frame.wall.bpp, &data->tile_frame.wall.size_line, &data->tile_frame.wall.type);
	data->tile_frame.floor.data = mlx_get_data_addr(data->tile_frame.floor.image, &data->tile_frame.floor.bpp, &data->tile_frame.floor.size_line, &data->tile_frame.floor.type);
	//data->tile_frame.open_e.data = mlx_get_data_addr(data->tile_frame.open_e.image, &data->tile_frame.open_e.bpp, &data->tile_frame.open_e.size_line, &data->tile_frame.open_e.type);
	//data->tile_frame.closed_e.data = mlx_get_data_addr(data->tile_frame.closed_e.image, &data->tile_frame.closed_e.bpp, &data->tile_frame.closed_e.size_line, &data->tile_frame.closed_e.type);
	data->tile_frame.enemy.image = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm", &data->tile_frame.enemy.width, &data->tile_frame.enemy.height);
	data->tile_frame.enemy.data = mlx_get_data_addr(data->tile_frame.enemy.image, &data->tile_frame.enemy.bpp, &data->tile_frame.enemy.size_line, &data->tile_frame.enemy.type);
}

void	load_collectibles(t_solong *data)
{
	data->tile_frame.c1[0].image = mlx_xpm_file_to_image(data->mlx, "textures/c1_1.xpm", &data->tile_frame.c1[0].width, &data->tile_frame.c1[0].height);
	get_adr_collectibles(data);
}

void	get_adr_collectibles(t_solong *data)
{
	data->tile_frame.c1[0].data = mlx_get_data_addr(data->tile_frame.c1[0].image, &data->tile_frame.c1[0].bpp, &data->tile_frame.c1[0].size_line, &data->tile_frame.c1[0].type);
}

void	load_menu_select(t_solong *data)
{
	data->menu.credits_menu.image = mlx_xpm_file_to_image(data->mlx, "textures/credits_menu.xpm", &data->menu.credits_menu.width, &data->menu.credits_menu.height);
	data->menu.play_menu.image = mlx_xpm_file_to_image(data->mlx, "textures/play_menu.xpm", &data->menu.play_menu.width, &data->menu.play_menu.height);
	data->menu.credits_menu.data = mlx_get_data_addr(data->menu.credits_menu.image, &data->menu.credits_menu.bpp, &data->menu.credits_menu.size_line, &data->menu.credits_menu.type);
	data->menu.play_menu.data = mlx_get_data_addr(data->menu.play_menu.image, &data->menu.play_menu.bpp, &data->menu.play_menu.size_line, &data->menu.play_menu.type);
	data->menu.p_select_0.image = mlx_xpm_file_to_image(data->mlx, "textures/p_select_0.xpm", &data->menu.p_select_0.width, &data->menu.p_select_0.height);
	data->menu.p_select_1.image = mlx_xpm_file_to_image(data->mlx, "textures/p_select_1.xpm", &data->menu.p_select_1.width, &data->menu.p_select_1.height);
	data->menu.p_select_0.data = mlx_get_data_addr(data->menu.p_select_0.image, &data->menu.p_select_0.bpp, &data->menu.p_select_0.size_line, &data->menu.p_select_0.type);
	data->menu.p_select_1.data = mlx_get_data_addr(data->menu.p_select_1.image, &data->menu.p_select_1.bpp, &data->menu.p_select_1.size_line, &data->menu.p_select_1.type);
}