/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:28:40 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 18:43:10 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_down(t_solong *data)
{
	data->tile_frame.player.down_1[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_down_0.xpm", &data->tile_frame.player.down_1[0].width,
			&data->tile_frame.player.down_1[0].height);
	data->tile_frame.player.down_1[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_down_1.xpm", &data->tile_frame.player.down_1[1].width,
			&data->tile_frame.player.down_1[1].height);
	data->tile_frame.player.down_1[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_down_2.xpm", &data->tile_frame.player.down_1[2].width,
			&data->tile_frame.player.down_1[2].height);
	data->tile_frame.player.down_1[0].data
		= mlx_get_data_addr(data->tile_frame.player.down_1[0].image,
			&data->tile_frame.player.down_1[0].bpp,
			&data->tile_frame.player.down_1[0].size_line,
			&data->tile_frame.player.down_1[0].type);
	data->tile_frame.player.down_1[1].data
		= mlx_get_data_addr(data->tile_frame.player.down_1[1].image,
			&data->tile_frame.player.down_1[1].bpp,
			&data->tile_frame.player.down_1[1].size_line,
			&data->tile_frame.player.down_1[1].type);
	data->tile_frame.player.down_1[2].data
		= mlx_get_data_addr(data->tile_frame.player.down_1[2].image,
			&data->tile_frame.player.down_1[2].bpp,
			&data->tile_frame.player.down_1[2].size_line,
			&data->tile_frame.player.down_1[2].type);
}

static void	load_up(t_solong *data)
{
	data->tile_frame.player.up_1[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_up_0.xpm", &data->tile_frame.player.up_1[0].width,
			&data->tile_frame.player.up_1[0].height);
	data->tile_frame.player.up_1[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_up_1.xpm", &data->tile_frame.player.up_1[1].width,
			&data->tile_frame.player.up_1[1].height);
	data->tile_frame.player.up_1[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_up_2.xpm", &data->tile_frame.player.up_1[2].width,
			&data->tile_frame.player.up_1[2].height);
	data->tile_frame.player.up_1[0].data
		= mlx_get_data_addr(data->tile_frame.player.up_1[0].image,
			&data->tile_frame.player.up_1[0].bpp,
			&data->tile_frame.player.up_1[0].size_line,
			&data->tile_frame.player.up_1[0].type);
	data->tile_frame.player.up_1[1].data
		= mlx_get_data_addr(data->tile_frame.player.up_1[1].image,
			&data->tile_frame.player.up_1[1].bpp,
			&data->tile_frame.player.up_1[1].size_line,
			&data->tile_frame.player.up_1[1].type);
	data->tile_frame.player.up_1[2].data
		= mlx_get_data_addr(data->tile_frame.player.up_1[2].image,
			&data->tile_frame.player.up_1[2].bpp,
			&data->tile_frame.player.up_1[2].size_line,
			&data->tile_frame.player.up_1[2].type);
}

static void	load_left(t_solong *data)
{
	data->tile_frame.player.left_1[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_left_0.xpm", &data->tile_frame.player.left_1[0].width,
			&data->tile_frame.player.left_1[0].height);
	data->tile_frame.player.left_1[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_left_1.xpm", &data->tile_frame.player.left_1[1].width,
			&data->tile_frame.player.left_1[1].height);
	data->tile_frame.player.left_1[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_left_2.xpm", &data->tile_frame.player.left_1[2].width,
			&data->tile_frame.player.left_1[2].height);
	data->tile_frame.player.left_1[0].data
		= mlx_get_data_addr(data->tile_frame.player.left_1[0].image,
			&data->tile_frame.player.left_1[0].bpp,
			&data->tile_frame.player.left_1[0].size_line,
			&data->tile_frame.player.left_1[0].type);
	data->tile_frame.player.left_1[1].data
		= mlx_get_data_addr(data->tile_frame.player.left_1[1].image,
			&data->tile_frame.player.left_1[1].bpp,
			&data->tile_frame.player.left_1[1].size_line,
			&data->tile_frame.player.left_1[1].type);
	data->tile_frame.player.left_1[2].data
		= mlx_get_data_addr(data->tile_frame.player.left_1[2].image,
			&data->tile_frame.player.left_1[2].bpp,
			&data->tile_frame.player.left_1[2].size_line,
			&data->tile_frame.player.left_1[2].type);
}

static void	load_right(t_solong *data)
{
	data->tile_frame.player.right_1[0].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_right_0.xpm", &data->tile_frame.player.right_1[0].width,
			&data->tile_frame.player.right_1[0].height);
	data->tile_frame.player.right_1[1].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_right_1.xpm", &data->tile_frame.player.right_1[1].width,
			&data->tile_frame.player.right_1[1].height);
	data->tile_frame.player.right_1[2].image = mlx_xpm_file_to_image(data->mlx,
			"textures/1_right_2.xpm", &data->tile_frame.player.right_1[2].width,
			&data->tile_frame.player.right_1[2].height);
	data->tile_frame.player.right_1[0].data
		= mlx_get_data_addr(data->tile_frame.player.right_1[0].image,
			&data->tile_frame.player.right_1[0].bpp,
			&data->tile_frame.player.right_1[0].size_line,
			&data->tile_frame.player.right_1[0].type);
	data->tile_frame.player.right_1[1].data
		= mlx_get_data_addr(data->tile_frame.player.right_1[1].image,
			&data->tile_frame.player.right_1[1].bpp,
			&data->tile_frame.player.right_1[1].size_line,
			&data->tile_frame.player.right_1[1].type);
	data->tile_frame.player.right_1[2].data
		= mlx_get_data_addr(data->tile_frame.player.right_1[2].image,
			&data->tile_frame.player.right_1[2].bpp,
			&data->tile_frame.player.right_1[2].size_line,
			&data->tile_frame.player.right_1[2].type);
}

void	load_player_1(t_solong *data)
{
	load_down(data);
	load_up(data);
	load_left(data);
	load_right(data);
}
