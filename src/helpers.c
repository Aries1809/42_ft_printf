/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/05 01:14:34 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/05 01:33:24 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	ft_putchar_all(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putstr_all(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

size_t	ft_intlen(long long n)
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

size_t	ft_putnbr_all(int n, int fd)
{
	char		buffer[11];
	int			i;
	long long	nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_fd(buffer[i], fd);
	}
	return (ft_intlen(nb));
}
