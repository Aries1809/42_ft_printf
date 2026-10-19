/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/03 13:15:56 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*s;
	long long	n1;
	size_t		len;

	n1 = n;
	len = ft_intlen(n1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n1 == 0)
		s[0] = '0';
	if (n1 < 0)
	{
		s[0] = '-';
		n1 = -n1;
	}
	while (n1 > 0)
	{
		s[--len] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (s);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_itoa.c libft.a -o /tmp/ft_itoa_test
/tmp/ft_itoa_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char *s;

	s = ft_itoa(0);
	assert(s != NULL);
	assert(strcmp(s, "0") == 0);
	free(s);

	s = ft_itoa(-42);
	assert(s != NULL);
	assert(strcmp(s, "-42") == 0);
	free(s);

	s = ft_itoa(INT_MIN);
	assert(s != NULL);
	assert(strcmp(s, "-2147483648") == 0);
	free(s);

	s = ft_itoa(INT_MAX);
	assert(s != NULL);
	assert(strcmp(s, "2147483647") == 0);
	free(s);
	puts("ft_itoa: all tests passed");
	return (0);
}
*/
