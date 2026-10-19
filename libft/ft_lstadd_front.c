/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/07 02:07:48 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	if (!lst || !n)
		return ;
	n->next = *lst;
	*lst = n;
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstadd_front.c libft.a -o /tmp/ft_lstadd_front_test
/tmp/ft_lstadd_front_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	t_list a = {"first", NULL};
	t_list b = {"second", NULL};
	t_list *head = NULL;

	ft_lstadd_front(&head, &a);
	assert(head == &a && a.next == NULL);
	ft_lstadd_front(&head, &b);
	assert(head == &b && b.next == &a && a.next == NULL);
	puts("ft_lstadd_front: all tests passed");
	return (0);
}
*/
