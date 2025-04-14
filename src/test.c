void	data_init(t_solong *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->map.col_count * 64, data->map.row_count * 64, "So Long");
	data->final_screen.image = mlx_new_image(data->mlx, data->map.col_count * 64, data->map.row_count * 64);
	data->final_screen.width = data->map.col_count * 64;
	data->final_screen.height = data->map.row_count * 64;
	printf("final screen width in data init() -> %d\n final screen height in data init() -> %d\n", data->final_screen.width, data->final_screen.height);
	data->final_screen.data = mlx_get_data_addr(data->final_screen.image, &data->final_screen.bpp, &data->final_screen.size_line, &data->final_screen.type);
	load_map(data);
	load_collectibles(data);
	load_player(data);
	draw_tiles(data);
	mlx_put_image_to_window(data->mlx, data->window, data->final_screen.image, 0, 0);
	mlx_loop(data->mlx);
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
	else if (i == 3 || i == 4)
		put_img_to_screen(&data->final_screen, data->tile_frame.c4.frame_1, x * 64, y * 64);
}