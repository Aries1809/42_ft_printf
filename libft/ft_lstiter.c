/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstiter.c libft.a -o /tmp/ft_lstiter_test
/tmp/ft_lstiter_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void test_increment(void *content)
{
	(*(int *)content)++;
}

int	main(void)
{
	int x = 1;
	int y = 2;
	t_list b = {&y, NULL};
	t_list a = {&x, &b};

	ft_lstiter(&a, test_increment);
	assert(x == 2 && y == 3);
	assert(a.next == &b && b.next == NULL);
	ft_lstiter(NULL, test_increment);
	puts("ft_lstiter: all tests passed");
	return (0);
}
*/
