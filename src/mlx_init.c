/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/12 02:33:38 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	data_init(t_solong *data)
{
	printf("gr");
	data->mlx = mlx_init();
	printf("after init");
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "So Long");
	data->final_screen.image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->final_screen.data = mlx_get_data_addr(data->final_screen.image, &data->final_screen.bpp, &data->final_screen.size_line, &data->final_screen.type);
	load_map(data);
	load_collectibles(data);
	load_player(data);
	printf("after wind");
	draw_tiles(data);
	mlx_put_image_to_window(data->mlx, data->window, data->final_screen.image, 0, 0);
	mlx_loop(data->mlx);
}

void	draw_tiles(t_solong *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while(data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			printf("X: %d Y: %d, img: %p\n", x * 64, y * 64, data->tile_frame.wall.image);
			if (data->map.map[x][y] == '1')
				put_img_to_screen(&data->final_screen, data->tile_frame.wall, x * 64, y * 64);
			else if (data->map.map[x][y] == '0')
				put_img_to_screen(&data->final_screen, data->tile_frame.floor, x * 64, y * 64);
			if (data->map.map[x][y] == 'P')
			{
				put_img_to_screen(&data->final_screen, data->tile_frame.floor, x * 64, y * 64);
				put_img_to_screen(&data->final_screen, data->tile_frame.player.f_stand, x * 64, y * 64);
			}
			else if (data->map.map[x][y] == 'C')
			{
				i = rand() / (RAND_MAX / 4);
				if (i == 0)
					put_img_to_screen(&data->final_screen, data->tile_frame.c1.frame_1, x * 64, y * 64);
				else if (i == 1)
					put_img_to_screen(&data->final_screen, data->tile_frame.c2.frame_1, x * 64, y * 64);
				else if (i == 2)
					put_img_to_screen(&data->final_screen, data->tile_frame.c3.frame_1, x * 64, y * 64);
				else if (i == 3 || i ==  4)
					put_img_to_screen(&data->final_screen, data->tile_frame.c4.frame_1, x * 64, y * 64);
			}
			y++;
		}
		x++;
	}
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	pixel = img->data + (x * img->size_line + y * 4);
	*(unsigned int *)pixel = color;
}

void	put_img_to_screen(t_img *screen, t_img img, int screen_x, int screen_y)
{
	int		x;
	int		y;
	int		tmp_y;
	char	*color;

	x = 0;
	while (x < img.height)
	{
		y = 0;
		tmp_y = screen_y;
		while (y < img.width)
		{
			color = img.data + (x * img.size_line + y * 4);
			if (*(int *)color >= 0)
				pixel_put(screen, screen_x, tmp_y, *(int *)color);
			y++;
			tmp_y++;
		}
		x++;
		screen_x++;
	}
}
