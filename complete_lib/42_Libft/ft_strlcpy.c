/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:06:25 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/08 15:08:58 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		i = src_len;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char *src = "123456789";
// 	char dest1[20];
// 	char dest2[20];
// 	size_t i = ft_strlcpy(dest1, src, 5);
// 	size_t j = strlcpy(dest2, src, 5);
// 	printf("My Func : %zu\n", i);
// 	printf("My Func : %s\n", dest1);
// 	printf("Original Func : %zu\n", j);
// 	printf("Original Func : %s\n", dest2);
// 	return (0);
// }