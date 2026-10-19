/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:50:10 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (i == 0)
			return (NULL);
		i--;
	}
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strrchr.c libft.a -o /tmp/ft_strrchr_test
/tmp/ft_strrchr_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	const char *s = "banana";

	assert(ft_strrchr(s, 'a') == s + 5);
	assert(ft_strrchr(s, 'z') == NULL);
	assert(ft_strrchr(s, '\0') == s + 6);
	assert(ft_strrchr(s, 'a' + 256) == s + 5);
	puts("ft_strrchr: all tests passed");
	return (0);
}
*/
