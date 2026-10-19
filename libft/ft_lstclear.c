/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/06 00:37:03 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		if (del)
			del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstclear.c libft.a -o /tmp/ft_lstclear_test
/tmp/ft_lstclear_test

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
	t_list *head = NULL;
	t_list *node;
	char *content;
	int i;

	for (i = 0; i < 3; i++)
	{
		content = ft_strdup("hello");
		assert(content != NULL);
		node = ft_lstnew(content);
		assert(node != NULL);
		ft_lstadd_back(&head, node);
	}
	ft_lstclear(&head, test_delete);
	assert(head == NULL && test_deleted == 3);
	ft_lstclear(&head, test_delete);
	assert(test_deleted == 3);
	puts("ft_lstclear: all tests passed");
	return (0);
}
*/
