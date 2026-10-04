/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:27:37 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/03 15:24:28 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_hex(size_t dec, int check);
void	ft_putuint_fd(unsigned int n, int fd);
void	ft_memaddr(void *ptr);

#endif
