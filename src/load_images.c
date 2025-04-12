/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:41:11 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/12 01:52:16 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_player(t_solong *data)
{
	data->tile_frame.player.f_stand.image = mlx_xpm_file_to_image(data->mlx, "textures/f_stand.xpm", &data->tile_frame.player.f_stand.width, &data->tile_frame.player.f_stand.height);
	data->tile_frame.player.l_walk_1.image = mlx_xpm_file_to_image(data->mlx, "textures/l_walk_1.xpm", &data->tile_frame.player.l_walk_1.width, &data->tile_frame.player.l_walk_1.height);
	data->tile_frame.player.l_walk_2.image = mlx_xpm_file_to_image(data->mlx, "textures/l_walk_2.xpm", &data->tile_frame.player.l_walk_2.width, &data->tile_frame.player.l_walk_2.height);
	data->tile_frame.player.r_walk_1.image = mlx_xpm_file_to_image(data->mlx, "textures/r_walk_1.xpm", &data->tile_frame.player.r_walk_1.width, &data->tile_frame.player.r_walk_1.height);
	data->tile_frame.player.r_walk_2.image = mlx_xpm_file_to_image(data->mlx, "textures/r_walk_2.xpm", &data->tile_frame.player.r_walk_2.width, &data->tile_frame.player.r_walk_2.height);
	data->tile_frame.player.u_walk_1.image = mlx_xpm_file_to_image(data->mlx, "textures/u_walk_1.xpm", &data->tile_frame.player.u_walk_1.width, &data->tile_frame.player.u_walk_1.height);
	data->tile_frame.player.u_walk_2.image = mlx_xpm_file_to_image(data->mlx, "textures/u_walk_2.xpm", &data->tile_frame.player.u_walk_1.width, &data->tile_frame.player.u_walk_2.height);
	data->tile_frame.player.d_walk_1.image = mlx_xpm_file_to_image(data->mlx, "textures/d_walk_1.xpm", &data->tile_frame.player.d_walk_1.width, &data->tile_frame.player.d_walk_1.height);
	data->tile_frame.player.d_walk_2.image = mlx_xpm_file_to_image(data->mlx, "textures/d_walk_2.xpm", &data->tile_frame.player.d_walk_2.width, &data->tile_frame.player.d_walk_2.height);
	data->tile_frame.player.f_stand.data = mlx_get_data_addr(data->tile_frame.player.f_stand.image, &data->tile_frame.player.f_stand.bpp, &data->tile_frame.player.f_stand.size_line, &data->tile_frame.player.f_stand.type);
//	data->tile_frame.player.l_walk_1.data = mlx_get_data_addr(data->tile_frame.player.l_walk_1.image, &data->tile_frame.player.l_walk_1.bpp, &data->tile_frame.player.l_walk_1.size_line, &data->tile_frame.player.l_walk_1.type);
//	data->tile_frame.player.l_walk_2.data = mlx_get_data_addr(data->tile_frame.player.l_walk_2.image, &data->tile_frame.player.l_walk_2.bpp, &data->tile_frame.player.l_walk_2.size_line, &data->tile_frame.player.l_walk_2.type);
//	data->tile_frame.player.r_walk_1.data = mlx_get_data_addr(data->tile_frame.player.r_walk_1.image, &data->tile_frame.player.r_walk_1.bpp, &data->tile_frame.player.r_walk_1.size_line, &data->tile_frame.player.r_walk_1.type);
//	data->tile_frame.player.r_walk_2.data = mlx_get_data_addr(data->tile_frame.player.r_walk_2.image, &data->tile_frame.player.r_walk_2.bpp, &data->tile_frame.player.r_walk_2.size_line, &data->tile_frame.player.r_walk_2.type);
//	data->tile_frame.player.u_walk_1.data = mlx_get_data_addr(data->tile_frame.player.u_walk_1.image, &data->tile_frame.player.u_walk_1.bpp, &data->tile_frame.player.u_walk_1.size_line, &data->tile_frame.player.u_walk_1.type);
//	data->tile_frame.player.u_walk_2.data = mlx_get_data_addr(data->tile_frame.player.u_walk_2.image, &data->tile_frame.player.u_walk_2.bpp, &data->tile_frame.player.u_walk_2.size_line, &data->tile_frame.player.u_walk_2.type);
//	data->tile_frame.player.d_walk_1.data = mlx_get_data_addr(data->tile_frame.player.d_walk_1.image, &data->tile_frame.player.d_walk_1.bpp, &data->tile_frame.player.d_walk_1.size_line, &data->tile_frame.player.d_walk_1.type);
//	data->tile_frame.player.d_walk_2.data = mlx_get_data_addr(data->tile_frame.player.d_walk_2.image, &data->tile_frame.player.d_walk_2.bpp, &data->tile_frame.player.d_walk_2.size_line, &data->tile_frame.player.d_walk_2.type);

}

void	load_map(t_solong *data)
{
	data->tile_frame.wall.image = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &data->tile_frame.wall.width, &data->tile_frame.wall.height);
    data->tile_frame.floor.image = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &data->tile_frame.floor.width, &data->tile_frame.floor.height);
	data->tile_frame.open_e.image = mlx_xpm_file_to_image(data->mlx, "textures/open_e.xpm", &data->tile_frame.open_e.width, &data->tile_frame.open_e.height);
	data->tile_frame.closed_e.image =mlx_xpm_file_to_image(data->mlx, "textures/l_walk_1.xpm", &data->tile_frame.closed_e.width, &data->tile_frame.closed_e.height);
	data->tile_frame.wall.data = mlx_get_data_addr(data->tile_frame.wall.image, &data->tile_frame.wall.bpp, &data->tile_frame.wall.size_line, &data->tile_frame.wall.type);
	data->tile_frame.floor.data = mlx_get_data_addr(data->tile_frame.floor.image, &data->tile_frame.floor.bpp, &data->tile_frame.floor.size_line, &data->tile_frame.floor.type);
//	data->tile_frame.open_e.data = mlx_get_data_addr(data->tile_frame.open_e.image, &data->tile_frame.open_e.bpp, &data->tile_frame.open_e.size_line, &data->tile_frame.open_e.type);
//	data->tile_frame.closed_e.data = mlx_get_data_addr(data->tile_frame.closed_e.image, &data->tile_frame.closed_e.bpp, &data->tile_frame.closed_e.size_line, &data->tile_frame.closed_e.type);
}

void	load_collectibles(t_solong *data)
{
	data->tile_frame.c1.frame_1.image = mlx_xpm_file_to_image(data->mlx, "textures/c1_1.xpm", &data->tile_frame.c1.frame_1.width, &data->tile_frame.c1.frame_1.height);
	data->tile_frame.c1.frame_2.image = mlx_xpm_file_to_image(data->mlx, "textures/c1_2.xpm", &data->tile_frame.c1.frame_2.width, &data->tile_frame.c1.frame_1.height);
	data->tile_frame.c1.frame_3.image = mlx_xpm_file_to_image(data->mlx, "textures/c1_3.xpm", &data->tile_frame.c1.frame_3.width, &data->tile_frame.c1.frame_1.height);
	data->tile_frame.c1.frame_4.image = mlx_xpm_file_to_image(data->mlx, "textures/c1_4.xpm", &data->tile_frame.c1.frame_4.width, &data->tile_frame.c1.frame_1.height);
	data->tile_frame.c2.frame_1.image = mlx_xpm_file_to_image(data->mlx, "textures/c2_1.xpm", &data->tile_frame.c2.frame_1.width, &data->tile_frame.c2.frame_1.height);
	data->tile_frame.c2.frame_2.image = mlx_xpm_file_to_image(data->mlx, "textures/c2_2.xpm", &data->tile_frame.c2.frame_2.width, &data->tile_frame.c2.frame_1.height);
	data->tile_frame.c2.frame_3.image = mlx_xpm_file_to_image(data->mlx, "textures/c2_3.xpm", &data->tile_frame.c2.frame_3.width, &data->tile_frame.c2.frame_1.height);
	data->tile_frame.c2.frame_4.image = mlx_xpm_file_to_image(data->mlx, "textures/c2_4.xpm", &data->tile_frame.c2.frame_4.width, &data->tile_frame.c2.frame_1.height);
	data->tile_frame.c3.frame_1.image = mlx_xpm_file_to_image(data->mlx, "textures/c3_1.xpm", &data->tile_frame.c3.frame_1.width, &data->tile_frame.c3.frame_1.height);
	data->tile_frame.c3.frame_2.image = mlx_xpm_file_to_image(data->mlx, "textures/c3_2.xpm", &data->tile_frame.c3.frame_2.width, &data->tile_frame.c3.frame_1.height);
	data->tile_frame.c3.frame_3.image = mlx_xpm_file_to_image(data->mlx, "textures/c3_3.xpm", &data->tile_frame.c3.frame_3.width, &data->tile_frame.c3.frame_1.height);
	data->tile_frame.c3.frame_4.image = mlx_xpm_file_to_image(data->mlx, "textures/c3_4.xpm", &data->tile_frame.c3.frame_4.width, &data->tile_frame.c3.frame_1.height);
	data->tile_frame.c4.frame_1.image = mlx_xpm_file_to_image(data->mlx, "textures/c4_1.xpm", &data->tile_frame.c4.frame_1.width, &data->tile_frame.c4.frame_1.height);
	data->tile_frame.c4.frame_2.image = mlx_xpm_file_to_image(data->mlx, "textures/c4_2.xpm", &data->tile_frame.c4.frame_2.width, &data->tile_frame.c4.frame_1.height);
	data->tile_frame.c4.frame_3.image = mlx_xpm_file_to_image(data->mlx, "textures/c4_3.xpm", &data->tile_frame.c4.frame_3.width, &data->tile_frame.c4.frame_1.height);
	data->tile_frame.c4.frame_4.image = mlx_xpm_file_to_image(data->mlx, "textures/c4_4.xpm", &data->tile_frame.c4.frame_4.width, &data->tile_frame.c4.frame_1.height);
	get_adr_collectibles(data);
}

void	get_adr_collectibles(t_solong *data)
{
	data->tile_frame.c1.frame_1.data = mlx_get_data_addr(data->tile_frame.c1.frame_1.image, &data->tile_frame.c1.frame_1.bpp, &data->tile_frame.c1.frame_1.size_line, &data->tile_frame.c1.frame_1.type);
//	data->tile_frame.c1.frame_2.data = mlx_get_data_addr(data->tile_frame.c1.frame_2.image, &data->tile_frame.c1.frame_2.bpp, &data->tile_frame.c1.frame_2.size_line, &data->tile_frame.c1.frame_2.type);
//	data->tile_frame.c1.frame_3.data = mlx_get_data_addr(data->tile_frame.c1.frame_3.image, &data->tile_frame.c1.frame_3.bpp, &data->tile_frame.c1.frame_3.size_line, &data->tile_frame.c1.frame_3.type);
//	data->tile_frame.c1.frame_4.data = mlx_get_data_addr(data->tile_frame.c1.frame_4.image, &data->tile_frame.c1.frame_4.bpp, &data->tile_frame.c1.frame_4.size_line, &data->tile_frame.c1.frame_4.type);
	data->tile_frame.c2.frame_1.data = mlx_get_data_addr(data->tile_frame.c2.frame_1.image, &data->tile_frame.c2.frame_1.bpp, &data->tile_frame.c2.frame_1.size_line, &data->tile_frame.c2.frame_1.type);
//	data->tile_frame.c2.frame_2.data = mlx_get_data_addr(data->tile_frame.c2.frame_2.image, &data->tile_frame.c2.frame_2.bpp, &data->tile_frame.c2.frame_2.size_line, &data->tile_frame.c2.frame_2.type);
//	data->tile_frame.c2.frame_3.data = mlx_get_data_addr(data->tile_frame.c2.frame_3.image, &data->tile_frame.c2.frame_3.bpp, &data->tile_frame.c2.frame_3.size_line, &data->tile_frame.c2.frame_3.type);
//	data->tile_frame.c2.frame_4.data = mlx_get_data_addr(data->tile_frame.c2.frame_4.image, &data->tile_frame.c2.frame_4.bpp, &data->tile_frame.c2.frame_4.size_line, &data->tile_frame.c2.frame_4.type);
	data->tile_frame.c3.frame_1.data = mlx_get_data_addr(data->tile_frame.c3.frame_1.image, &data->tile_frame.c3.frame_1.bpp, &data->tile_frame.c3.frame_1.size_line, &data->tile_frame.c3.frame_1.type);
//	data->tile_frame.c3.frame_2.data = mlx_get_data_addr(data->tile_frame.c3.frame_2.image, &data->tile_frame.c3.frame_2.bpp, &data->tile_frame.c3.frame_2.size_line, &data->tile_frame.c3.frame_2.type);
//	data->tile_frame.c3.frame_3.data = mlx_get_data_addr(data->tile_frame.c3.frame_3.image, &data->tile_frame.c3.frame_3.bpp, &data->tile_frame.c3.frame_3.size_line, &data->tile_frame.c3.frame_3.type);
//	data->tile_frame.c3.frame_4.data = mlx_get_data_addr(data->tile_frame.c3.frame_4.image, &data->tile_frame.c3.frame_4.bpp, &data->tile_frame.c3.frame_4.size_line, &data->tile_frame.c3.frame_4.type);
	data->tile_frame.c4.frame_1.data = mlx_get_data_addr(data->tile_frame.c4.frame_1.image, &data->tile_frame.c4.frame_1.bpp, &data->tile_frame.c4.frame_1.size_line, &data->tile_frame.c4.frame_1.type);
//	data->tile_frame.c4.frame_2.data = mlx_get_data_addr(data->tile_frame.c4.frame_2.image, &data->tile_frame.c4.frame_2.bpp, &data->tile_frame.c4.frame_2.size_line, &data->tile_frame.c4.frame_2.type);
//	data->tile_frame.c4.frame_3.data = mlx_get_data_addr(data->tile_frame.c4.frame_3.image, &data->tile_frame.c4.frame_3.bpp, &data->tile_frame.c4.frame_3.size_line, &data->tile_frame.c4.frame_3.type);
//	data->tile_frame.c4.frame_4.data = mlx_get_data_addr(data->tile_frame.c4.frame_4.image, &data->tile_frame.c4.frame_4.bpp, &data->tile_frame.c4.frame_4.size_line, &data->tile_frame.c4.frame_4.type);
}