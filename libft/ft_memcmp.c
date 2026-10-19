/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:26:24 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(const unsigned char *)s1 != *(const unsigned char *)s2)
			return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_memcmp.c libft.a -o /tmp/ft_memcmp_test
/tmp/ft_memcmp_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	const unsigned char a[] = {0, 128, 2};
	const unsigned char b[] = {0, 127, 3};

	assert(ft_memcmp(a, b, 0) == 0);
	assert(ft_memcmp(a, b, 1) == 0);
	assert(ft_memcmp(a, b, 3) > 0);
	assert(ft_memcmp(b, a, 3) < 0);
	puts("ft_memcmp: all tests passed");
	return (0);
}
*/