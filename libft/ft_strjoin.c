/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:40:57 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, len1);
	ft_memcpy(ret + len1, s2, len2 + 1);
	return (ret);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strjoin.c libft.a -o /tmp/ft_strjoin_test
/tmp/ft_strjoin_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char *s;

	s = ft_strjoin("hello", " world");
	assert(s != NULL);
	assert(strcmp(s, "hello world") == 0);
	free(s);

	s = ft_strjoin("", "");
	assert(s != NULL);
	assert(strcmp(s, "") == 0);
	free(s);
	puts("ft_strjoin: all tests passed");
	return (0);
}
*/
