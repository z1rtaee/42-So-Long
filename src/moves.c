/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:24:12 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/14 22:28:05 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int key_handle(int keycode, t_solong *data)
{
	if (keycode == XK_Escape)
		exit_game("Thank you for playing!");
	else if (keycode == XK_Left || keycode == XK_a)
	{
		if (!check_collision(data, keycode))
		{
			data->player.pos_y -= PLAYER_SPEED;
			data->player.farthest_y -= PLAYER_SPEED;
			update_map(data, keycode);
		}
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		if (!check_collision(data, keycode))
		{
			data->player.pos_y += PLAYER_SPEED;
			data->player.farthest_y += PLAYER_SPEED;
			update_map(data, keycode);
		}
	}
	else if (keycode == XK_Up || keycode == XK_w)
	{
		if (!check_collision(data, keycode))
		{
			data->player.pos_x -= PLAYER_SPEED;
			data->player.farthest_x -= PLAYER_SPEED;
			update_map(data, keycode);
		}
	}
	else if (keycode == XK_Down || keycode == XK_s)
	{
		if (!check_collision(data, keycode))
		{
			data->player.pos_x += PLAYER_SPEED;
			data->player.farthest_x += PLAYER_SPEED;
			update_map(data, keycode);
		}
	}
	return (0);
}

void	handle_scroll(t_solong *data)
{
	int max_x;
	int max_y;

	max_x = data->final_screen.height - HEIGHT;
	max_y = data->final_screen.width - WIDTH;
	if (data->view_y < 0)
		data->view_y = 0;
	if (data->view_x < 0)
		data->view_x = 0;
	if (data->view_y > max_y)
		data->view_y = max_y;
	if (data->view_x > max_x)
		data->view_x = max_x;
}

void	adjust_view(t_solong *data)
{
	if (data->player.pos_x < data->view_x + (64 * 4))
		data->view_x = data->player.pos_x - (64 * 4);
	else if (data->player.farthest_x > data->view_x + HEIGHT - (64 * 4))
		data->view_x = data->player.farthest_x - (HEIGHT - (64 * 4));
	if (data->player.pos_y < data->view_y + (64 * 4))
		data->view_y = data->player.pos_y - (64 * 4);
	else if (data->player.farthest_y > data->view_y + WIDTH - (64 * 4))
		data->view_y = data->player.farthest_y - (WIDTH - (64 * 4));
	handle_scroll(data);
}

void	update_map(t_solong *data, int key_pressed)
{
	int	map_p_pos_x;
	int map_p_pos_y;

	map_p_pos_x = (data->player.pos_x + 32) / 64;
	map_p_pos_y = (data->player.pos_y + 16) / 64;
	data->map.map[map_p_pos_x][map_p_pos_y] = 'P';
	if ((key_pressed == XK_Left || key_pressed == XK_a) && data->map.map[map_p_pos_x][map_p_pos_y + 1] != '1')
		data->map.map[map_p_pos_x][map_p_pos_y + 1] = '0';
	else if ((key_pressed == XK_Right || key_pressed == XK_d) && data->map.map[map_p_pos_x][map_p_pos_y - 1] != '1')
		data->map.map[map_p_pos_x][map_p_pos_y - 1] = '0';
	else if ((key_pressed == XK_Up || key_pressed == XK_w) && data->map.map[map_p_pos_x + 1][map_p_pos_y] != '1')
		data->map.map[map_p_pos_x + 1][map_p_pos_y] = '0';
	else if ((key_pressed == XK_Down || key_pressed == XK_s) && data->map.map[map_p_pos_x - 1][map_p_pos_y] != '1')
		data->map.map[map_p_pos_x - 1][map_p_pos_y] = '0';
}

int	check_collision(t_solong *data, int key_pressed)
{
	int	center_x;
	int	center_y;

	center_x = (data->player.pos_x + 32) / 64;
	center_y = (data->player.pos_y + 16) / 64;
	if (key_pressed == XK_Left || key_pressed == XK_a)
		return (data->map.map[center_x][center_y - 1] == '1');
	else if (key_pressed == XK_Right || key_pressed == XK_d)
		return (data->map.map[center_x][center_y + 1] == '1');
	else if (key_pressed == XK_Up || key_pressed == XK_w)
		return (data->map.map[center_x - 1][center_y] == '1');
	else if (key_pressed == XK_Down || key_pressed == XK_s)
		return (data->map.map[center_x + 1][center_y] == '1');
	return (0);
}
