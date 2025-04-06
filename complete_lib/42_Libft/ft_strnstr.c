/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:43:28 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:19 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < len && s1[i])
	{
		j = 0;
		while (i + j < len && s2[j])
		{
			if (s2[j] != s1[i + j])
				break ;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "Sweater";
// 	char *s2 = "eat";
// 	printf("My Func : %s\n", ft_strnstr(s1, s2, sizeof(s1)));
// 	return (0);
// }