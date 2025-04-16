/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:46:45 by miovu             #+#    #+#             */
/*   Updated: 2025/01/28 17:23:15 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i])
			i++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	if (start == end)
		return (NULL);
	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start + i < end)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split_part1(char **result, const char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && j < (int)count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i++;
		while (s[i] != c && s[i])
			i++;
		end = i;
		result[j++] = fill_word(s, start, end);
		if (!result[j - 1])
			return (ft_free(result, j - 2));
		if (s[i])
			i++;
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (!result)
		return (NULL);
	result = ft_split_part1(result, s, c);
	return (result);
}

/* #include <stdio.h>
int	main()
{
	char	*s = "Hello world, how are  you doing?";
	char 	c = ' ';
	char	**str;
	int 	i = 0;

	str = ft_split(s, c);
	while (str[i])
	{
		printf("Word %d: %s\n", i, str[i]);
		i++;
	}
	ft_free(str, i);
	return (0);
} */
