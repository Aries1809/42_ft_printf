/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/07 02:20:03 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		new_node = ft_lstnew(mapped_content);
		if (!new_node)
		{
			del(mapped_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
TEST MAIN: Remove this block's opening and closing comment markers to run.
Uncomment one main at a time. From the project directory:
make
cc -Wall -Wextra -Werror ft_lstmap.c libft.a -o /tmp/ft_lstmap_test
/tmp/ft_lstmap_test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void *test_double(void *content)
{
	int *result;

	result = malloc(sizeof(*result));
	assert(result != NULL);
	*result = *(int *)content * 2;
	return (result);
}

int	main(void)
{
	int x = 1;
	int y = 2;
	t_list b = {&y, NULL};
	t_list a = {&x, &b};
	t_list *mapped;

	mapped = ft_lstmap(&a, test_double, free);
	assert(mapped != NULL && mapped != &a);
	assert(mapped->next != NULL && mapped->next != &b);
	assert(*(int *)mapped->content == 2);
	assert(*(int *)mapped->next->content == 4);
	assert(mapped->next->next == NULL);
	assert(x == 1 && y == 2);
	ft_lstclear(&mapped, free);
	assert(mapped == NULL);
	assert(ft_lstmap(NULL, test_double, free) == NULL);
	puts("ft_lstmap: all tests passed");
	return (0);
}
*/
