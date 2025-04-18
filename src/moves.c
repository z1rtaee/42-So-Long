/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:24:12 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/18 22:29:13 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int	key_released(int keycode, t_solong *data)
{
	if (keycode == XK_Up || keycode == XK_w)
		data->keys.w = 0;
	if (keycode == XK_Left || keycode == XK_a)
		data->keys.a = 0;
	if (keycode == XK_Down || keycode == XK_s)
		data->keys.s = 0;
	if (keycode == XK_Right || keycode == XK_d)
		data->keys.d = 0;
	return (0);
}

int	key_pressed(int keycode, t_solong *data)
{
	if (keycode == XK_Escape)
		exit_game("Thank you for playing!", data);
	if (keycode == XK_Up || keycode == XK_w)
		data->keys.w = 1;
	if (keycode == XK_Left || keycode == XK_a)
		data->keys.a = 1;
	if (keycode == XK_Down || keycode == XK_s)
		data->keys.s = 1;
	if (keycode == XK_Right || keycode == XK_d)
		data->keys.d = 1;
	return (0);
}

void	handle_scroll(t_solong *data)
{
	int	max_x;
	int	max_y;

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
	if (data->map.map[data->player.pos_x / 64][data->player.pos_y / 64] == 'E')
		if (data->map.c_collected == data->map.c_count)
		{
			printf("pls\n");
			exit_game("You win! :p", data);
		}
	if (data->map.map[(data->player.pos_x + 32) / 64][(data->player.pos_y + 32) / 64] == 'C')
	{
		data->map.c_collected++;
		printf("baddie nr %d collected\n", data->map.c_collected);
		data->map.map[(data->player.pos_x + 32) / 64][(data->player.pos_y + 32) / 64] = '0';
	}
	data->map.map[data->player.pos_x / 64][data->player.pos_y / 64] = 'P';
	if ((key_pressed == XK_Left || key_pressed == XK_a)
		&& data->map.map[data->player.pos_x / 64][(data->player.pos_y + PLAYER_SPEED) / 64] != '1')
		data->map.map[data->player.pos_x / 64][(data->player.pos_y + PLAYER_SPEED) / 64] = '0';
	else if ((key_pressed == XK_Right || key_pressed == XK_d)
		&& data->map.map[data->player.pos_x / 64][(data->player.pos_y - PLAYER_SPEED) / 64] != '1')
		data->map.map[data->player.pos_x / 64][(data->player.pos_y - PLAYER_SPEED) / 64] = '0';
	else if ((key_pressed == XK_Up || key_pressed == XK_w)
		&& data->map.map[(data->player.pos_x + PLAYER_SPEED) / 64][data->player.pos_y / 64] != '1')
		data->map.map[(data->player.pos_x + PLAYER_SPEED) / 64][data->player.pos_y / 64] = '0';
	else if ((key_pressed == XK_Down || key_pressed == XK_s)
		&& data->map.map[(data->player.pos_x - PLAYER_SPEED) / 64][data->player.pos_y / 64] != '1')
		data->map.map[(data->player.pos_x - PLAYER_SPEED) / 64][data->player.pos_y / 64] = '0';
}

int	check_collision(t_solong *data, int key_pressed)
{
	if (key_pressed == XK_Left || key_pressed == XK_a)
		return (data->map.map[data->player.pos_x / 64][(data->player.pos_y - PLAYER_SPEED) / 64] == '1' || data->map.map[data->player.farthest_x / 64][(data->player.pos_y - PLAYER_SPEED) / 64] == '1');
	else if (key_pressed == XK_Right || key_pressed == XK_d)
		return (data->map.map[data->player.pos_x / 64][(data->player.farthest_y + PLAYER_SPEED) / 64] == '1' || data->map.map[data->player.farthest_x / 64][(data->player.farthest_y + PLAYER_SPEED) / 64] == '1');
	else if (key_pressed == XK_Up || key_pressed == XK_w)
		return (data->map.map[(data->player.pos_x - PLAYER_SPEED) / 64][data->player.pos_y / 64] == '1' || data->map.map[(data->player.pos_x - PLAYER_SPEED) / 64][data->player.farthest_y / 64] == '1');
	else if (key_pressed == XK_Down || key_pressed == XK_s)
		return (data->map.map[(data->player.farthest_x + PLAYER_SPEED) / 64][data->player.pos_y / 64] == '1' || data->map.map[(data->player.farthest_x + PLAYER_SPEED) / 64][data->player.farthest_y / 64] == '1');
	return (0);
}
