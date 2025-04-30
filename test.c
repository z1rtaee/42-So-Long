void	data_init(t_solong *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->map.col_count * 64, data->map.row_count * 64, "So Long");
	data->screen.image = mlx_new_image(data->mlx, data->map.col_count * 64, data->map.row_count * 64);
	data->screen.width = data->map.col_count * 64;
	data->screen.height = data->map.row_count * 64;
	//printf("final screen width in data init() -> %d\n final screen height in data init() -> %d\n", data->screen.width, data->screen.height);
	data->screen.data = mlx_get_data_addr(data->screen.image, &data->screen.bpp, &data->screen.size_line, &data->screen.type);
	load_map(data);
	load_collectibles(data);
	load_player(data);
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->window, data->screen.image, 0, 0);
	mlx_loop(data->mlx);
}

else if (data->map.map[x][y] == 'C')
{
	i = rand() / (RAND_MAX / 4);
	if (i == 0)
		put_img_to_screen(&data->screen, data->tile_frame.c1.frame_1, x * 64, y * 64);
	else if (i == 1)
		put_img_to_screen(&data->screen, data->tile_frame.c2.frame_1, x * 64, y * 64);
	else if (i == 2)
		put_img_to_screen(&data->screen, data->tile_frame.c3.frame_1, x * 64, y * 64);
	else if (i == 3 || i == 4)
		put_img_to_screen(&data->screen, data->tile_frame.c4.frame_1, x * 64, y * 64);
}


// int	key_handle(int keycode, t_solong *data)
// {
// 	if (keycode == XK_Escape)
// 		exit_game("Thank you for playing!", data);
// 	else if (keycode == XK_Left || keycode == XK_a)
// 	{
// 		if (!check_collision(data, keycode))
// 		{
// 			data->player.pos_y -= PLAYER_SPEED;
// 			data->player.farthest_y -= PLAYER_SPEED;
// 			update_map(data, keycode);
// 		}
// 	}
// 	else if (keycode == XK_Right || keycode == XK_d)
// 	{
// 		if (!check_collision(data, keycode))
// 		{
// 			data->player.pos_y += PLAYER_SPEED;
// 			data->player.farthest_y += PLAYER_SPEED;
// 			update_map(data, keycode);
// 		}
// 	}
// 	else if (keycode == XK_Up || keycode == XK_w)
// 	{
// 		if (!check_collision(data, keycode))
// 		{
// 			data->player.pos_x -= PLAYER_SPEED;
// 			data->player.farthest_x -= PLAYER_SPEED;
// 			update_map(data, keycode);
// 		}
// 	}
// 	else if (keycode == XK_Down || keycode == XK_s)
// 	{
// 		if (!check_collision(data, keycode))
// 		{
// 			data->player.pos_x += PLAYER_SPEED;
// 			data->player.farthest_x += PLAYER_SPEED;
// 			update_map(data, keycode);
// 		}
// 	}
// 	return (0);
// }

// ——— MENU INPUT ———————————————————————————————————————————————
static int handle_menu_input(int key, t_solong *d)
{
    if (key == XK_Up || key == XK_w || key == XK_Down || key == XK_s)
        d->menu_choice = 1 - d->menu_choice;  // toggle between 0 and 1
    else if (key == XK_Return)
    {
        if (d->menu_choice == 0)
            d->status = PLAYER_SELECT;
        else
            d->status = CREDITS;
    }
    else if (key == XK_Escape)
        exit_game("Goodbye!", d);
    return (0);
}

// ——— CREDITS INPUT ————————————————————————————————————————————
static int handle_credits_input(int key, t_solong *d)
{
    if (key == XK_Escape || key == XK_Return)
        d->status = MENU;
    return (0);
}

// ——— PLAYER‑SELECT INPUT ———————————————————————————————————————
static int handle_select_input(int key, t_solong *d)
{
    const int N = /* number of choices */;
    if (key == XK_Left || key == XK_a)
        d->select_choice = (d->select_choice + N - 1) % N;
    else if (key == XK_Right || key == XK_d)
        d->select_choice = (d->select_choice + 1) % N;
    else if (key == XK_Return)
        d->status = GAME;
    else if (key == XK_Escape)
        d->status = MENU;
    return (0);
}

// ——— GAMEPLAY INPUT ————————————————————————————————————————
static int handle_game_input(int key, t_solong *d)
{
    if (key == XK_Escape)
        exit_game("Thanks for playing!", d);
    if (key == XK_Up    || key == XK_w) d->keys.w = 1;
    if (key == XK_Left  || key == XK_a) d->keys.a = 1;
    if (key == XK_Down  || key == XK_s) d->keys.s = 1;
    if (key == XK_Right || key == XK_d) d->keys.d = 1;
    return (0);
}

// ——— MAIN DISPATCHER ————————————————————————————————————————
int key_pressed(int keycode, t_solong *data)
{
    switch (data->status)
    {
        case MENU:           return handle_menu_input(  keycode, data);
        case CREDITS:        return handle_credits_input(keycode, data);
        case PLAYER_SELECT:  return handle_select_input(keycode, data);
        case GAME:           return handle_game_input(  keycode, data);
    }
    return (0);
}
