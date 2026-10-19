/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s + start, len);
	ret[len] = '\0';
	return (ret);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_substr.c libft.a -o /tmp/ft_substr_test
/tmp/ft_substr_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char *s;

	s = ft_substr("hello", 1, 3);
	assert(s != NULL);
	assert(strcmp(s, "ell") == 0);
	free(s);

	s = ft_substr("hello", 99, 2);
	assert(s != NULL);
	assert(strcmp(s, "") == 0);
	free(s);

	s = ft_substr("hello", 3, 99);
	assert(s != NULL);
	assert(strcmp(s, "lo") == 0);
	free(s);

	s = ft_substr("hello", 0, 0);
	assert(s != NULL);
	assert(strcmp(s, "") == 0);
	free(s);
	puts("ft_substr: all tests passed");
	return (0);
}
*/
