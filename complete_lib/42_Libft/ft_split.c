/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:45:15 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:42:01 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		count++;
	}
	return (count);
}

char	*alloc_word(char *s, char c)
{
	int	i;

	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		return (ft_substr(s, 0, i));
	}
	return (NULL);
}

void	free_dp(char **dp)
{
	int	x;

	x = -1;
	while (dp[++x])
		free(dp[x]);
	free(dp);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < word)
	{
		while (s[j] && s[j] == c)
			j++;
		res[i] = alloc_word(s + j, c);
		if (!res[i])
			return (free_dp(res), NULL);
		while (s[j] && s[j] != c)
			j++;
	}
	res[i] = NULL;
	return (res);
}

// int	main(void)
// {
// 	unsigned int i = 0;
// 	unsigned int j = 0;
// 	printf("%p\n", *ft_split("               ", ' '));
// 	return (0);
// }