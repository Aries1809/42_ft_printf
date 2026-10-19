/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	ld;
	size_t	ls;

	i = ft_strlen(dst);
	n = 0;
	ld = i;
	ls = ft_strlen(src);
	if (size <= ld)
		return (size + ls);
	while (src[n] && i < size - 1)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	return (ld + ls);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strlcat.c libft.a -o /tmp/ft_strlcat_test
/tmp/ft_strlcat_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char buf[8] = "hi";

	assert(ft_strlcat(buf, " there!", sizeof(buf)) == 9);
	assert(strcmp(buf, "hi ther") == 0);
	assert(ft_strlcat(buf, "abc", 2) == 5);
	assert(strcmp(buf, "hi ther") == 0);
	assert(ft_strlcat(buf, "abc", 0) == 3);
	puts("ft_strlcat: all tests passed");
	return (0);
}
*/
