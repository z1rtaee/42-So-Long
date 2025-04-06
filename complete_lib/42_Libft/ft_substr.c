/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:42:36 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:40:07 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	stsub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (free(s), ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (free(s), NULL);
	stsub = 0;
	while (stsub < len && s[start])
	{
		sub[stsub] = s[start];
		start++;
		stsub++;
	}
	sub[stsub] = '\0';
	return (free(s), sub);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("Batata Frita", 7, 13));
// 	return (0);
// }