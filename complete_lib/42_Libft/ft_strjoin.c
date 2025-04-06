/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:31 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/08 16:10:35 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	r;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	r = 0;
	while (s1[i])
		result[r++] = s1[i++];
	i = 0;
	while (s2[i])
		result[r++] = s2[i++];
	result[r] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char *s1 = "ola";
// 	char *s2 = "adeus";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }