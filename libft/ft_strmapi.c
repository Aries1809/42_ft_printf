/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:48:01 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	if (!s || !f)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_strmapi.c libft.a -o /tmp/ft_strmapi_test
/tmp/ft_strmapi_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static char test_map(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char *s;

	s = ft_strmapi("abcd", test_map);
	assert(s != NULL && strcmp(s, "aceg") == 0);
	free(s);
	s = ft_strmapi("", test_map);
	assert(s != NULL && s[0] == '\0');
	free(s);
	puts("ft_strmapi: all tests passed");
	return (0);
}
*/
