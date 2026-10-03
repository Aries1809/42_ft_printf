/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 18:13:45 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/02 14:23:41 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "libft.h"
#include <unistd.h>
#include <stdio.h>

size_t	count_args(const char *str)
{
	size_t	ret;

	ret = 0;
	while (*(str++))
	{
		if (*str == '%' && *(str + 1) != '%')
			ret++;
	}
	return (ret);
}

/*
#include <stdio.h>
int main(){
	printf("%zu\n", count_args((const char*)"%%i%am a%n %%apple%%"));
}
*/
