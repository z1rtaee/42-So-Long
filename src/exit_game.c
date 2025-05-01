/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:21:25 by bpires-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:06:44 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_solong *data, char *str)
{
	if (str)
		free(str);
	if (data->map.map)
		free_ar((void **)data->map.map);
	if (data->map.map_cpy)
		free_ar((void **)data->map.map_cpy);
	if (data->screen.image)
		mlx_destroy_image(data->mlx, data->screen.image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	destroy_image(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	exit_error(char *error_message, t_solong *data, char *str, int fd)
{
	if (str)
		free(str);
	if (data->map.map)
		free_ar((void **)data->map.map);
	if (data->map.map_cpy)
		free_ar((void **)data->map.map_cpy);
	if (fd > -1)
		close(fd);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	exit_game(char *end_game, t_solong *data)
{
	free_all(data, NULL);
	ft_putendl_fd(end_game, 1);
	exit(EXIT_SUCCESS);
}

int	x_window(t_solong *data)
{
	exit_game("Thank you for playing!", data);
	return (0);
}
