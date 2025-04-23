/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:21:19 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/23 01:00:26 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	render_game(t_solong *data)
{
	char	*moves;
	
	moves = ft_itoa(data->player.move_count);
	if (data->status == MENU)
		render_menu(data);
	else if (data->status == PLAYER_SELECT)
		render_p_select(data);
	else if (data->status == GAME){
		render_gameplay(data);
		mlx_string_put(data->mlx, data->window, 20, 1000, 0xFFFFFF, moves);
		free(moves);
	}
//	else if (data->status == CREDITS)
//		render_credits(data);
	return (0);
}

void    render_menu(t_solong *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->menu.play_menu.image, 0, 0);
	if (data->menu_choice == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->menu.play_menu.image, 0, 0);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->menu.credits_menu.image, 0, 0);
}

void    render_p_select(t_solong *data)
{
	mlx_clear_window(data->mlx, data->window);
	if (data->player_choice == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->menu.p_select_0.image, 0, 0);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->menu.p_select_1.image, 0, 0);
	if (data->player_choice == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->menu.p_select_1.image, 0, 0);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->menu.p_select_0.image, 0, 0);
}

void    render_gameplay(t_solong *data)
{
	player_movement(data);
	adjust_view(data);
	//update__anim
	draw_tiles(data);
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->final_screen.image, -data->view_y, -data->view_x);
	//PICK AND DRAW CORRECT FRAME
}

//void    render_credits(t_solong *data)
//{
//	
//}