/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 13:41:28 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_screen(t_solong *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			draw_tiles(data, x, y);
			if (data->player_choice == 0)
				draw_player_0(data);
			else if (data->player_choice == 1)
				draw_player_1(data);
			y++;
		}
		x++;
	}
}

void	draw_tiles(t_solong *data, int x, int y)
{
	if (data->map.map[x][y] == '1')
		put_img_to_screen(&data->screen, data->tile_frame.wall, x * 64, y * 64);
	else if (data->map.map[x][y] == '0')
		put_img_to_screen(&data->screen, data->tile_frame.floor, x * 64, y
			* 64);
	else if (data->map.map[x][y] == 'P')
		put_img_to_screen(&data->screen, data->tile_frame.floor, x * 64, y
			* 64);
	else if (data->map.map[x][y] == 'C')
	{
		put_img_to_screen(&data->screen, data->tile_frame.floor, x * 64, y
			* 64);
		put_img_to_screen(&data->screen, data->tile_frame.c1[0], x * 64, y
			* 64);
	}
	else if (data->map.map[x][y] == 'F')
	{
		put_img_to_screen(&data->screen, data->tile_frame.floor, x * 64, y
			* 64);
		put_img_to_screen(&data->screen, data->tile_frame.enemy, x * 64, y
			* 64);
	}
	else if (data->map.map[x][y] == 'E')
		put_img_to_screen(&data->screen, data->tile_frame.exit, x * 64, y * 64);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= img->height || y >= img->width)
		return ;
	pixel = img->data + (x * img->size_line + y * 4);
	*(unsigned int *)pixel = color;
}

void	put_img_to_screen(t_img *screen, t_img img, int screen_x, int screen_y)
{
	int		x;
	int		y;
	char	*color;

	x = 0;
	while (x < img.height)
	{
		y = 0;
		while (y < img.width)
		{
			color = img.data + (x * img.size_line + y * 4);
			if (*(int *)color >= 0)
				pixel_put(screen, screen_x + x, screen_y + y, *(int *)color);
			y++;
		}
		x++;
	}
}
