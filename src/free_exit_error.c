/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:21:25 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/12 16:49:36 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_solong *data)
{
	if (data->map.map)
		free_ar((void **)data->map.map);
	if (data->map.map_cpy)
		free_ar((void **)data->map.map_cpy);
}

void	exit_error(char *error_message, t_solong *data, char *str, int fd)
{
	free_all(data);
	if (str)
		free(str);
	if (fd > -1)
		close(fd);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	exit_game(char *end_game)
{
	ft_putendl_fd(end_game, 1);
	exit(EXIT_SUCCESS);
}