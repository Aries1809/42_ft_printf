/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:33:21 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = c;
	return (s);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_memset.c libft.a -o /tmp/ft_memset_test
/tmp/ft_memset_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	unsigned char buf[5] = {1, 2, 3, 4, 5};

	assert(ft_memset(buf, 0x141, 3) == buf);
	assert(memcmp(buf, "AAA\4\5", 5) == 0);
	assert(ft_memset(buf, 0, 0) == buf);
	assert(buf[0] == 'A');
	puts("ft_memset: all tests passed");
	return (0);
}
*/
