/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/07 02:02:20 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		if (lst->content)
			del(lst->content);
		free(lst);
	}
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstdelone.c libft.a -o /tmp/ft_lstdelone_test
/tmp/ft_lstdelone_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static int test_deleted;

static void test_delete(void *content)
{
	test_deleted++;
	free(content);
}

int	main(void)
{
	t_list *node;
	char *content;

	content = ft_strdup("hello");
	assert(content != NULL);
	node = ft_lstnew(content);
	assert(node != NULL);
	ft_lstdelone(node, test_delete);
	assert(test_deleted == 1);
	ft_lstdelone(NULL, test_delete);
	assert(test_deleted == 1);
	puts("ft_lstdelone: all tests passed");
	return (0);
}
*/
