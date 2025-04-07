/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:21:25 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/07 01:32:35 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *error_message, char *str, int fd)
{
	if (str)
		free(str);
	if (fd >= 0)
		close(fd);
	ft_putendl_fd(error_message, 2);
	exit(1);
}

