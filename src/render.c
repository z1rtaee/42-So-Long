/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:21:19 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/19 23:36:31 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	render_game(t_solong *data)
{
	if (data->status == MENU)
		render_menu(data);
	else if (data->status == PLAYER_SELECT)
		render_p_select(data);
	else if (data->status == GAME)
		render_gameplay(data);
//	else if (data->status == CREDITS)
//		render_credits(data);
	return (0);
}

void    render_menu(t_solong *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_string_put(data->mlx, data->window, 100, 100, 0xFFFFFF, "▶ Play");
	mlx_string_put(data->mlx, data->window, 100, 150, 0xFFFFFF, "  Credits");
	if (data->menu_choice == 0)
		mlx_string_put(data->mlx, data->window, 80, 100, 0xFFFFFF, ">");
	else
		mlx_string_put(data->mlx, data->window, 80, 150, 0xFFFFFF, ">");
}

void    render_p_select(t_solong *data)
{
	int	color_0;
	int	color_1;

	color_0 = 0;
	color_1 = 0;
	mlx_clear_window(data->mlx, data->window);
	mlx_string_put(data->mlx, data->window, 100, 100, 0xFFFFFF, "Select your player:");
	if (data->player_choice == 0)
		color_0 = 0xFF0000;
	else
		color_0 = 0xFFFFFF;
	mlx_string_put(data->mlx, data->window, 120, 120, color_0, "Player 0");
	if (data->player_choice == 1)
		color_1 = 0xFF0000;
	else
		color_1 = 0xFFFFFF;
	mlx_string_put(data->mlx, data->window, 120, 160, color_1, "Player 1");
}

void    render_gameplay(t_solong *data)
{
	player_movement(data);
	adjust_view(data);
	draw_tiles(data);
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->final_screen.image, -data->view_y, -data->view_x);
}

//void    render_credits(t_solong *data)
//{
//	
//}