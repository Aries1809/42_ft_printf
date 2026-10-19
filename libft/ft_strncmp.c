/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strncmp.c libft.a -o /tmp/ft_strncmp_test
/tmp/ft_strncmp_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	assert(ft_strncmp("abc", "abd", 2) == 0);
	assert(ft_strncmp("abc", "abd", 3) < 0);
	assert(ft_strncmp("abd", "abc", 3) > 0);
	assert(ft_strncmp("", "a", 1) < 0);
	assert(ft_strncmp("x", "y", 0) == 0);
	assert(ft_strncmp("\200", "\177", 1) > 0);
	puts("ft_strncmp: all tests passed");
	return (0);
}
*/
