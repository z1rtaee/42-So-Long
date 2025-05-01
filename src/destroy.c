/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:05:16 by bpires-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:42:01 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void destroy_map(t_solong *data)
{
	if (data->tile_frame.c1[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.c1[0].image);
	if (data->tile_frame.wall.image)
		mlx_destroy_image(data->mlx, data->tile_frame.wall.image);
	if (data->tile_frame.floor.image)
		mlx_destroy_image(data->mlx, data->tile_frame.floor.image);
	if (data->tile_frame.exit.image)
		mlx_destroy_image(data->mlx, data->tile_frame.exit.image);
	if (data->tile_frame.enemy.image)
		mlx_destroy_image(data->mlx, data->tile_frame.enemy.image);
}

static void destroy_player_0(t_solong *data)
{
	if (data->tile_frame.player.down_0[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_0[0].image);
	if (data->tile_frame.player.down_0[1].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_0[1].image);
	if (data->tile_frame.player.down_0[2].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_0[2].image);
	if (data->tile_frame.player.up_0[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.up_0[0].image);
	if (data->tile_frame.player.up_0[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.up_0[1].image);
	if (data->tile_frame.player.up_0[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.up_0[2].image);
	if (data->tile_frame.player.left_0[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.left_0[0].image);
	if (data->tile_frame.player.left_0[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.left_0[1].image);
	if (data->tile_frame.player.left_0[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.left_0[2].image);
	if (data->tile_frame.player.right_0[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.right_0[0].image);
	if (data->tile_frame.player.right_0[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.right_0[1].image);
	if (data->tile_frame.player.right_0[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.right_0[2].image);
}

static void destroy_player_1(t_solong *data)
{
	if (data->tile_frame.player.down_1[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_1[0].image);
	if (data->tile_frame.player.down_1[1].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_1[1].image);
	if (data->tile_frame.player.down_1[2].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.down_1[2].image);
	if (data->tile_frame.player.up_1[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.up_1[0].image);
	if (data->tile_frame.player.up_1[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.up_1[1].image);
	if (data->tile_frame.player.up_1[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.up_1[2].image);
	if (data->tile_frame.player.left_1[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.left_1[0].image);
	if (data->tile_frame.player.left_1[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.left_1[1].image);
	if (data->tile_frame.player.left_1[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.left_1[2].image);
	if (data->tile_frame.player.right_1[0].image)
		mlx_destroy_image(data->mlx, data->tile_frame.player.right_1[0].image);
	if (data->tile_frame.player.right_1[1].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.right_1[1].image);
	if (data->tile_frame.player.right_1[2].image)
    	mlx_destroy_image(data->mlx, data->tile_frame.player.right_1[2].image);
}

static void	destroy_menu_select_credits(t_solong *data)
{
	if (data->menu.credits_menu.image)
		mlx_destroy_image(data->mlx, data->menu.credits_menu.image);
	if (data->menu.play_menu.image)
		mlx_destroy_image(data->mlx, data->menu.play_menu.image);
	if (data->menu.p_select_0.image)
		mlx_destroy_image(data->mlx, data->menu.p_select_0.image);
	if (data->menu.p_select_1.image)
		mlx_destroy_image(data->mlx, data->menu.p_select_1.image);
	if (data->menu.credits.image)
		mlx_destroy_image(data->mlx, data->menu.credits.image);
}

void	destroy_image(t_solong *data)
{
	destroy_map(data);
	destroy_player_0(data);
	destroy_player_1(data);
	destroy_menu_select_credits(data);
}
