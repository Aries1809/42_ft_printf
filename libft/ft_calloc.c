/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:13:43 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	if (count != 0 && (total / count) != size)
		return (NULL);
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, total);
	return (p);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_calloc.c libft.a -o /tmp/ft_calloc_test
/tmp/ft_calloc_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	unsigned char *p;
	size_t i;

	p = ft_calloc(8, sizeof(*p));
	assert(p != NULL);
	for (i = 0; i < 8; i++)
		assert(p[i] == 0);
	free(p);
	assert(ft_calloc((size_t)-1, 2) == NULL);
	p = ft_calloc(0, 4);
	free(p);
	puts("ft_calloc: all tests passed");
	return (0);
}
*/
