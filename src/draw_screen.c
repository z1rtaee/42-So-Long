/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/18 20:44:20 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_tiles(t_solong *data)
{
	int	x;
	int	y;

	x = 0;
	//printf("player x -> %d\n player y -> %d\n", data->player.pos_x, data->player.pos_y);
	//intf("Screen dimensions: width = %d, height = %d\n", data->final_screen.width, data->final_screen.height);
	//printf("WIDTH = %d, HEIGHT = %d\n", WIDTH, HEIGHT);
	while(data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == '1')
				put_img_to_screen(&data->final_screen, data->tile_frame.wall, x * 64, y * 64);
			else if (data->map.map[x][y] == '0')
				put_img_to_screen(&data->final_screen, data->tile_frame.floor, x * 64, y * 64);
			if (data->map.map[x][y] == 'P')
				put_img_to_screen(&data->final_screen, data->tile_frame.floor, x * 64, y * 64);
			//	put_img_to_screen(&data->final_screen, data->tile_frame.player.f_stand, x * 64, y * 64);
			else if (data->map.map[x][y] == 'C')
			{
				put_img_to_screen(&data->final_screen, data->tile_frame.floor, x * 64, y * 64);
				put_img_to_screen(&data->final_screen, data->tile_frame.c1.frame_1, x * 64, y * 64);
			}
			//else if (data->map.map[x][y] == 'E')
				//put_img_to_screen(&data->final_screen, data->tile_frame.closed_e, x * 64, y * 64);
			put_img_to_screen(&data->final_screen, data->tile_frame.player.f_stand, data->player.pos_x, data->player.pos_y + 16);
			y++;
		}
		x++;
	}
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
			//printf("screen -> %p\n img -> %p\n x -> %p\n y -> %p\n", screen, &img, &screen_x, &screen_y);
			color = img.data + (x * img.size_line + y * 4);
			if (*(int *)color >= 0)
				pixel_put(screen, screen_x + x, screen_y + y, *(int *)color);
			y++;
		}
		x++;
	}
}

