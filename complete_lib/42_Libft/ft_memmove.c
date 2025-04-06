/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:26:24 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/08 14:57:48 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;

	if (!src && !dest)
		return (dest);
	csrc = (char *)src;
	cdest = (char *)dest;
	if (csrc < cdest)
		while (n--)
			cdest[n] = csrc[n];
	else
		ft_memcpy(cdest, csrc, n);
	return (dest);
}

// int	main(void)
// {
// 	char *src = "123456789";
// 	char dest[20];
// 	printf("My Func : %s\n", (char *)ft_memmove(dest, src, 3));
// 	printf("My Func : %s\n", (char *)memmove(dest, src, 3));
// 	return (0);
// }