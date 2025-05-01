/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:18:10 by bpires-r          #+#    #+#             */
/*   Updated: 2025/05/01 11:54:48 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	up_down(t_solong *data)
{
	if (data->keys.w && !check_collision(data, XK_Up)
		&& !check_exit_collision(data, XK_Up))
	{
		data->player.pos_x -= PLAYER_SPEED;
		data->player.farthest_x -= PLAYER_SPEED;
		data->player.move_count++;
		update_map(data);
	}
	if (data->keys.s && !check_collision(data, XK_Down)
		&& !check_exit_collision(data, XK_Down))
	{
		data->player.pos_x += PLAYER_SPEED;
		data->player.farthest_x += PLAYER_SPEED;
		data->player.move_count++;
		update_map(data);
	}
}

static void	left_right(t_solong *data)
{
	if (data->keys.a && !check_collision(data, XK_Left)
		&& !check_exit_collision(data, XK_Left))
	{
		data->player.pos_y -= PLAYER_SPEED;
		data->player.farthest_y -= PLAYER_SPEED;
		data->player.move_count++;
		update_map(data);
	}
	if (data->keys.d && !check_collision(data, XK_Right)
		&& !check_exit_collision(data, XK_Right))
	{
		data->player.pos_y += PLAYER_SPEED;
		data->player.farthest_y += PLAYER_SPEED;
		data->player.move_count++;
		update_map(data);
	}
}

void	player_movement(t_solong *data)
{
	up_down(data);
	left_right(data);
	if (data->keys.w || data->keys.a || data->keys.s || data->keys.d)
		data->frame++;
	if (data->frame * FRAME_TIME > FPS)
		data->frame = 0;
}
