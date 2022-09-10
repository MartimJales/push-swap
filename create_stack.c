/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:05:34 by mjales            #+#    #+#             */
/*   Updated: 2022/09/10 15:19:39 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list *create_list(int argc, char *argv[])
{
    t_list *lst;
    t_list *new;
    int	i;
    int num;

	lst = NULL;
	i = 0;
	while (i++ < argc - 1)
	{
        num = ft_atoi(argv[i]);
        new = ft_lstnew(num);
        ft_lstadd_back(&lst, new);
	}
    return (lst);
}

stacks *create_stacks(int argc, char *argv[])
{
	stacks *lists;
	t_list *a;
	t_list *b;
	char *s;

	lists = malloc(sizeof(stacks));
	s = NULL;
	a = create_list(argc, argv);
    b = NULL;
	lists->a = a;
	lists->b = b;
	lists->s = s;
	return (lists);
}

void print_stacks(stacks *lists)
{
	printf("A: ");
     while (lists->a)
     {
         printf("%d ", lists->a->content);
         lists->a = lists->a->next;
     }
	 printf("\nB: ");
     while (lists->b)
     {
         printf("%d ", lists->b->content);
         lists->b = lists->b->next;
     }
	 printf("\nS: %s\n", lists->s);
}
