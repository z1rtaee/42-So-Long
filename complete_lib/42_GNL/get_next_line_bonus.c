/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:15:22 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/04 17:18:30 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	t_gnl		data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.line = NULL;
	while (fd >= 0 && fd < FOPEN_MAX)
	{
		if (!buffer[fd][0])
		{
			data.bytes_count = read(fd, buffer[fd], BUFFER_SIZE);
			if (data.bytes_count == 0)
				return (result(data, buffer[fd], ft_clean_buffer, 0));
			if (data.bytes_count < 0)
				return (result(data, buffer[fd], ft_clean_buffer, 1));
		}
		data.line = ft_strjoin_gnl(data.line, buffer[fd], data);
		if (ft_strchr_gnl(buffer[fd], '\n', data))
			return (result(data, buffer[fd], ft_clean_buffer, 0));
		ft_clean_buffer (buffer[fd], data);
	}
	return (data.line);
}
