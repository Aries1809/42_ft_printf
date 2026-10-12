/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:12:02 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/11 17:14:55 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>

typedef struct s_flag
{
	size_t	minus;
	size_t	zero;
	size_t	dot;
	size_t	sharp;
	size_t	space;
	size_t	plus;
}			t_flag;

size_t	ft_hex(size_t dec, int check);
size_t	ft_memaddr(void *ptr);
int		ft_printf(const char *format, ...);
size_t	ft_putchar_all(char c, int fd);
size_t	ft_putnbr_all(long long n, int fd);
size_t	ft_putstr_all(char *s, int fd);

#endif
