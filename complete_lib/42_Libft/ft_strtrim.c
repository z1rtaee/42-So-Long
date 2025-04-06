/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:56:42 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:40:52 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	j;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (free(s1), ft_strdup(""));
	return (ft_substr(s1, i, j - i + 1));
}

// int	main(void)
// {
// 	char *s1 = "aba123aba";
// 	char *set = "ab";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }