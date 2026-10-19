/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strdup.c libft.a -o /tmp/ft_strdup_test
/tmp/ft_strdup_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char *s;

	s = ft_strdup("hello");
	assert(s != NULL);
	assert(strcmp(s, "hello") == 0);
	free(s);

	s = ft_strdup("");
	assert(s != NULL);
	assert(strcmp(s, "") == 0);
	free(s);
	puts("ft_strdup: all tests passed");
	return (0);
}
*/
