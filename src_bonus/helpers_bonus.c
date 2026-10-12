/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/05 01:14:34 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/11 17:07:29 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

size_t	ft_putchar_all(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_all(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (ft_putstr_all("(null)", 1));
	len = ft_strlen(s);
	return (write(fd, s, len));
}

size_t	ft_intlen(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

size_t	ft_putnbr_all(long long n, int fd)
{
	long long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_all(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (ft_intlen(nb));
}
