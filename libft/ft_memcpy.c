/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_memcpy.c libft.a -o /tmp/ft_memcpy_test
/tmp/ft_memcpy_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char buf[6] = "xxxxx";

	assert(ft_memcpy(buf, "ab\0cd", 5) == buf);
	assert(memcmp(buf, "ab\0cd", 5) == 0);
	assert(ft_memcpy(buf, "z", 0) == buf);
	assert(buf[0] == 'a');
	puts("ft_memcpy: all tests passed");
	return (0);
}
*/
