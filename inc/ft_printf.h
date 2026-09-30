/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:14:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 14:15:21 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef	struct s_flags
{
	bool	minus;
	bool	zero;
	bool	sharp;
	bool	space;
	bool	plus;
	int		width;
	int		precision;
}	t_flags;

int	ft_printf(const char *input, ...);

#endif
