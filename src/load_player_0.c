/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:56:44 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 18:42:58 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_down(t_solong *data)
{
	data->tile_frame.player.down_0[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/down_0.xpm", &data->tile_frame.player.down_0[0].width,
			&data->tile_frame.player.down_0[0].height);
	data->tile_frame.player.down_0[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/down_1.xpm", &data->tile_frame.player.down_0[1].width,
			&data->tile_frame.player.down_0[1].height);
	data->tile_frame.player.down_0[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/down_2.xpm", &data->tile_frame.player.down_0[2].width,
			&data->tile_frame.player.down_0[2].height);
	data->tile_frame.player.down_0[0].data
		= mlx_get_data_addr(data->tile_frame.player.down_0[0].image,
			&data->tile_frame.player.down_0[0].bpp,
			&data->tile_frame.player.down_0[0].size_line,
			&data->tile_frame.player.down_0[0].type);
	data->tile_frame.player.down_0[1].data
		= mlx_get_data_addr(data->tile_frame.player.down_0[1].image,
			&data->tile_frame.player.down_0[1].bpp,
			&data->tile_frame.player.down_0[1].size_line,
			&data->tile_frame.player.down_0[1].type);
	data->tile_frame.player.down_0[2].data
		= mlx_get_data_addr(data->tile_frame.player.down_0[2].image,
			&data->tile_frame.player.down_0[2].bpp,
			&data->tile_frame.player.down_0[2].size_line,
			&data->tile_frame.player.down_0[2].type);
}

static void	load_up(t_solong *data)
{
	data->tile_frame.player.up_0[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/up_0.xpm", &data->tile_frame.player.up_0[0].width,
			&data->tile_frame.player.up_0[0].height);
	data->tile_frame.player.up_0[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/up_1.xpm", &data->tile_frame.player.up_0[1].width,
			&data->tile_frame.player.up_0[1].height);
	data->tile_frame.player.up_0[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/up_2.xpm", &data->tile_frame.player.up_0[2].width,
			&data->tile_frame.player.up_0[2].height);
	data->tile_frame.player.up_0[0].data
		= mlx_get_data_addr(data->tile_frame.player.up_0[0].image,
			&data->tile_frame.player.up_0[0].bpp,
			&data->tile_frame.player.up_0[0].size_line,
			&data->tile_frame.player.up_0[0].type);
	data->tile_frame.player.up_0[1].data
		= mlx_get_data_addr(data->tile_frame.player.up_0[1].image,
			&data->tile_frame.player.up_0[1].bpp,
			&data->tile_frame.player.up_0[1].size_line,
			&data->tile_frame.player.up_0[1].type);
	data->tile_frame.player.up_0[2].data
		= mlx_get_data_addr(data->tile_frame.player.up_0[2].image,
			&data->tile_frame.player.up_0[2].bpp,
			&data->tile_frame.player.up_0[2].size_line,
			&data->tile_frame.player.up_0[2].type);
}

static void	load_left(t_solong *data)
{
	data->tile_frame.player.left_0[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/left_0.xpm", &data->tile_frame.player.left_0[0].width,
			&data->tile_frame.player.left_0[0].height);
	data->tile_frame.player.left_0[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/left_1.xpm", &data->tile_frame.player.left_0[1].width,
			&data->tile_frame.player.left_0[1].height);
	data->tile_frame.player.left_0[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/left_2.xpm", &data->tile_frame.player.left_0[2].width,
			&data->tile_frame.player.left_0[2].height);
	data->tile_frame.player.left_0[0].data
		= mlx_get_data_addr(data->tile_frame.player.left_0[0].image,
			&data->tile_frame.player.left_0[0].bpp,
			&data->tile_frame.player.left_0[0].size_line,
			&data->tile_frame.player.left_0[0].type);
	data->tile_frame.player.left_0[1].data
		= mlx_get_data_addr(data->tile_frame.player.left_0[1].image,
			&data->tile_frame.player.left_0[1].bpp,
			&data->tile_frame.player.left_0[1].size_line,
			&data->tile_frame.player.left_0[1].type);
	data->tile_frame.player.left_0[2].data
		= mlx_get_data_addr(data->tile_frame.player.left_0[2].image,
			&data->tile_frame.player.left_0[2].bpp,
			&data->tile_frame.player.left_0[2].size_line,
			&data->tile_frame.player.left_0[2].type);
}

static void	load_right(t_solong *data)
{
	data->tile_frame.player.right_0[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/right_0.xpm", &data->tile_frame.player.right_0[0].width,
			&data->tile_frame.player.right_0[0].height);
	data->tile_frame.player.right_0[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/right_1.xpm", &data->tile_frame.player.right_0[1].width,
			&data->tile_frame.player.right_0[1].height);
	data->tile_frame.player.right_0[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/right_2.xpm", &data->tile_frame.player.right_0[2].width,
			&data->tile_frame.player.right_0[2].height);
	data->tile_frame.player.right_0[0].data
		= mlx_get_data_addr(data->tile_frame.player.right_0[0].image,
			&data->tile_frame.player.right_0[0].bpp,
			&data->tile_frame.player.right_0[0].size_line,
			&data->tile_frame.player.right_0[0].type);
	data->tile_frame.player.right_0[1].data
		= mlx_get_data_addr(data->tile_frame.player.right_0[1].image,
			&data->tile_frame.player.right_0[1].bpp,
			&data->tile_frame.player.right_0[1].size_line,
			&data->tile_frame.player.right_0[1].type);
	data->tile_frame.player.right_0[2].data
		= mlx_get_data_addr(data->tile_frame.player.right_0[2].image,
			&data->tile_frame.player.right_0[2].bpp,
			&data->tile_frame.player.right_0[2].size_line,
			&data->tile_frame.player.right_0[2].type);
}

void	load_player_0(t_solong *data)
{
	load_down(data);
	load_up(data);
	load_left(data);
	load_right(data);
}
