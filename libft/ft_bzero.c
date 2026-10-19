/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:56 by sky             ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_bzero.c libft.a -o /tmp/ft_bzero_test
/tmp/ft_bzero_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	unsigned char buf[5] = {1, 2, 3, 4, 5};

	ft_bzero(buf, 3);
	assert(memcmp(buf, "\0\0\0\4\5", 5) == 0);
	ft_bzero(buf, 0);
	assert(buf[3] == 4);
	puts("ft_bzero: all tests passed");
	return (0);
}
*/
