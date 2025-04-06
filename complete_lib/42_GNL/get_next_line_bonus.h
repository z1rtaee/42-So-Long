/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:11:28 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/04 17:18:15 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				bytes_count;
	int				check;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*res;
	char			*line;
}					t_gnl;

char				*get_next_line(int fd);
size_t				ft_strlen_gnl(const char *s);
char				*ft_strchr_gnl(const char *s, int c, t_gnl data);
char				*ft_strjoin_gnl(char *s1, char const *s2, t_gnl data);
int					ft_clean_buffer(char buffer[BUFFER_SIZE + 1], t_gnl data);
char				*result(t_gnl data, char *buffer, int (*f)(char *, t_gnl),
						int i);

#endif