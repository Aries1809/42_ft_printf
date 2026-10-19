/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:45:49 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strlcpy.c libft.a -o /tmp/ft_strlcpy_test
/tmp/ft_strlcpy_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char buf[6] = "xxxxx";

	assert(ft_strlcpy(buf, "hello world", sizeof(buf)) == 11);
	assert(strcmp(buf, "hello") == 0);
	assert(ft_strlcpy(buf, "abc", 0) == 3);
	assert(strcmp(buf, "hello") == 0);
	assert(ft_strlcpy(buf, "abc", 1) == 3);
	assert(buf[0] == '\0');
	puts("ft_strlcpy: all tests passed");
	return (0);
}
*/