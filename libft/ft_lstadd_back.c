/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/07 01:59:52 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = n;
	else
		ft_lstadd_back(&((*lst)->next), n);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstadd_back.c libft.a -o /tmp/ft_lstadd_back_test
/tmp/ft_lstadd_back_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	t_list a = {"first", NULL};
	t_list b = {"second", NULL};
	t_list *head = NULL;

	ft_lstadd_back(&head, &a);
	assert(head == &a && a.next == NULL);
	ft_lstadd_back(&head, &b);
	assert(head == &a && a.next == &b && b.next == NULL);
	puts("ft_lstadd_back: all tests passed");
	return (0);
}
*/
