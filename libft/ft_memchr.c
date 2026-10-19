/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;

	if (!s)
		return (NULL);
	t = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*t == (unsigned char)c)
			return ((void *)t);
		t++;
	}
	return (NULL);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_memchr.c libft.a -o /tmp/ft_memchr_test
/tmp/ft_memchr_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	const unsigned char buf[] = {'a', 0, 'b', 'a'};

	assert(ft_memchr(buf, 'a', 4) == buf);
	assert(ft_memchr(buf, 0, 4) == buf + 1);
	assert(ft_memchr(buf, 'b', 2) == NULL);
	assert(ft_memchr(buf, 'a', 0) == NULL);
	assert(ft_memchr(buf, 'a' + 256, 4) == buf);
	puts("ft_memchr: all tests passed");
	return (0);
}
*/
