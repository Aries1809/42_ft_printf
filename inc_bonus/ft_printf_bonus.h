/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:12:02 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/06 15:13:07 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>

typedef struct t_flag
{
	size_t	minus;
	size_t	zero;
	size_t	dot;
}			t_flag;

int		ft_printf(const char *format, ...);

#endif
