/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:51:00 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 13:47:13 by bpires-r         ###   ########.fr       */
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
	if (data->status == MENU)
		return (handle_menu_input(keycode, data));
	else if (data->status == PLAYER_SELECT)
		return (handle_p_select_input(keycode, data));
	else if (data->status == GAME)
		return (handle_game_input(keycode, data));
	else if (keycode == XK_Escape)
		data->status = MENU;
	return (0);
}

int	handle_game_input(int keycode, t_solong *data)
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

int	handle_menu_input(int keycode, t_solong *data)
{
	if (keycode == XK_Up || keycode == XK_Down)
		data->menu_choice = 1 - data->menu_choice;
	else if (keycode == XK_Return)
	{
		if (data->menu_choice == 0)
			data->status = PLAYER_SELECT;
		else
			data->status = CREDITS;
	}
	else if (keycode == XK_Escape)
		exit_game("Goodbye!", data);
	return (0);
}

int	handle_p_select_input(int keycode, t_solong *data)
{
	if (keycode == XK_Right)
		data->player_choice = 0;
	else if (keycode == XK_Left)
		data->player_choice = 1;
	else if (keycode == XK_Return)
		data->status = GAME;
	else if (keycode == XK_Escape)
		data->status = MENU;
	printf("player choice -> %d\n", data->player_choice);
	return (0);
}
