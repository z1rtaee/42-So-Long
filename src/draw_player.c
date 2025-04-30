/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:23:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 13:41:19 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_player_0(t_solong *data)
{
	int	frame;

	frame = data->frame;
	frame = ((frame - 3) * FRAME_TIME) / (FPS / 3);
	if (data->keys.a)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.left_0[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.w)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.up_0[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.s)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.down_0[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.d)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.right_0[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else
		put_img_to_screen(&data->screen,
			data->tile_frame.player.down_0[1], data->player.pos_x,
			data->player.pos_y + 16);
}

void	draw_player_1(t_solong *data)
{
	int	frame;

	frame = data->frame;
	frame = ((frame - 3) * FRAME_TIME) / (FPS / 3);
	if (data->keys.a)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.left_1[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.w)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.up_1[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.s)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.down_1[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else if (data->keys.d)
		put_img_to_screen(&data->screen,
			data->tile_frame.player.right_1[frame], data->player.pos_x,
			data->player.pos_y + 16);
	else
		put_img_to_screen(&data->screen,
			data->tile_frame.player.down_1[1], data->player.pos_x,
			data->player.pos_y + 16);
}
