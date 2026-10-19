/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_striteri.c libft.a -o /tmp/ft_striteri_test
/tmp/ft_striteri_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void test_iter(unsigned int i, char *c)
{
	*c += i;
}

int	main(void)
{
	char s[] = "abcd";
	char empty[] = "";

	ft_striteri(s, test_iter);
	assert(strcmp(s, "aceg") == 0);
	ft_striteri(empty, test_iter);
	assert(empty[0] == '\0');
	puts("ft_striteri: all tests passed");
	return (0);
}
*/