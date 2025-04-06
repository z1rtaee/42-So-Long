/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:40:06 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/08 15:17:09 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char *src = "123456789";
// 	char dest1[20] = "Hello   ";
// 	char dest2[20] = "Hello   ";
// 	size_t i = ft_strlcat(dest1, src, sizeof(dest1));
// 	size_t j = strlcat(dest2, src, sizeof(dest2));
// 	printf("My Func : %zu\n", i);
// 	printf("My Func : %s\n", dest1);
// 	printf("Original Func : %zu\n", j);
// 	printf("Original Func : %s\n", dest2);
// 	return (0);
// }