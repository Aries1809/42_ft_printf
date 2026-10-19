/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_putnbr_fd.c libft.a -o /tmp/ft_putnbr_fd_test
/tmp/ft_putnbr_fd_test

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
	ft_putnbr_fd(INT_MIN, fds[1]);
	ft_putchar_fd(' ', fds[1]);
	ft_putnbr_fd(0, fds[1]);
	ft_putchar_fd(' ', fds[1]);
	ft_putnbr_fd(INT_MAX, fds[1]);
	assert(close(fds[1]) == 0);
	n = read(fds[0], buf, sizeof(buf) - 1);
	assert(n >= 0);
	buf[n] = '\0';
	assert(strcmp(buf, "-2147483648 0 2147483647") == 0);
	assert(close(fds[0]) == 0);
	puts("ft_putnbr_fd: all tests passed");
	return (0);
}
*/
