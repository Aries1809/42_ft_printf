/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_putchar_fd.c libft.a -o /tmp/ft_putchar_fd_test
/tmp/ft_putchar_fd_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	int fds[2];
	char buf[64];
	ssize_t n;

	assert(pipe(fds) == 0);
	ft_putchar_fd('A', fds[1]);
	assert(close(fds[1]) == 0);
	n = read(fds[0], buf, sizeof(buf) - 1);
	assert(n >= 0);
	buf[n] = '\0';
	assert(strcmp(buf, "A") == 0);
	assert(close(fds[0]) == 0);
	puts("ft_putchar_fd: all tests passed");
	return (0);
}
*/
