/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:31:58 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:35:52 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_gnl(const char *s, int c, t_gnl data)
{
	data.i = 0;
	while (s[data.i])
	{
		if (s[data.i] == (char)c)
			return ((char *)&s[data.i]);
		data.i++;
	}
	if (s[data.i] == (char)c)
		return ((char *)&s[data.i]);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	ft_clean_buffer(char buffer[BUFFER_SIZE + 1], t_gnl data)
{
	data.i = 0;
	data.j = 0;
	data.check = 0;
	while (data.i < BUFFER_SIZE)
	{
		if (data.check)
		{
			buffer[data.j] = buffer[data.i];
			data.j++;
		}
		if (buffer[data.i] == '\n')
			data.check = 1;
		buffer[data.i] = '\0';
		data.i++;
	}
	return (1);
}

char	*ft_strjoin_gnl(char *s1, char const *s2, t_gnl data)
{
	data.len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	data.res = (char *)malloc(sizeof(char) * (data.len + 1));
	if (!data.res)
		return (NULL);
	data.i = 0;
	data.j = 0;
	while (s1 && s1[data.i])
		data.res[data.j++] = s1[data.i++];
	data.i = 0;
	while (s2 && s2[data.i])
	{
		data.res[data.j++] = s2[data.i++];
		if (data.res[data.j - 1] == '\n')
			break ;
	}
	data.res[data.j] = '\0';
	if (s1)
		free(s1);
	return (data.res);
}

char	*result(t_gnl data, char *buffer, int (*f)(char *, t_gnl), int i)
{
	f(buffer, data);
	if (i == 1)
	{
		if (data.line)
			free(data.line);
		return (NULL);
	}
	return (data.line);
}
