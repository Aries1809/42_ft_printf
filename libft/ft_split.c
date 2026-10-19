/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/08 16:53:39 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || !s[1]))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_free_split(char **split, size_t n)
{
	while (n > 0)
		free(split[--n]);
	free(split);
	return (NULL);
}

static char	**ft_fill(char **split, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
				return (ft_free_split(split, i));
			i++;
			s += len;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (ft_fill(split, s, c));
}

/*
// TEST MAIN: Remove this block's opening and closing comment markers to run.
// Uncomment one main at a time. From the project directory:
// make
// cc -Wall -Wextra -Werror ft_split.c libft.a -o /tmp/ft_split_test
// /tmp/ft_split_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char **words;
	size_t i;

	words = ft_split("Hello", 0);
	printf("%s\n", words[1]);
	for (i = 0; words[i]; i++)
		free(words[i]);
	free(words);
	words = ft_split(",,hello,,world,", ',');
	assert(words != NULL);
	assert(words[0] && strcmp(words[0], "hello") == 0);
	assert(words[1] && strcmp(words[1], "world") == 0);
	assert(words[2] == NULL);
	for (i = 0; words[i]; i++)
		free(words[i]);
	free(words);
	words = ft_split("", ',');
	assert(words != NULL && words[0] == NULL);
	free(words);
	words = ft_split("hello", '\0');
	assert(words != NULL && words[0] != NULL);
	assert(strcmp(words[0], "hello") == 0 && words[1] == NULL);
	free(words[0]);
	free(words);
	puts("ft_split: all tests passed");
	return (0);
}
*/
