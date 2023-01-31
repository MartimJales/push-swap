/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:45:25 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 13:56:54 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stacks *lists)
{
	long	aux;

	aux = (long)(*lists).b->next->content;
	(*lists).b->next->content = (*lists).b->content;
	(*lists).b->content = (void *)aux;
	lists->s = ft_strjoin(lists->s, "sb\n");
}

void	push_b(t_stacks *lists)
{
	t_list	*new;

	new = NULL;
	if (lists->a != NULL)
	{
		new = lists->a->next;
		lists->a->next = lists->b;
		lists->b = lists->a;
		lists->a = new;
	}
	update_indexs(lists);
	lists->s = ft_strjoin(lists->s, "pb\n");
}

void	rotate_b(t_stacks *lists)
{
	t_list	*aux;

	aux = NULL;
	if (lists->b != NULL && lists->b->next != NULL)
	{
		aux = ft_lstlast(lists->b);
		aux->next = lists->b;
		lists->b = lists->b->next;
		aux->next->next = NULL;
	}
	lists->s = ft_strjoin(lists->s, "rb\n");
}

void	reverse_b(t_stacks *lists)
{
	t_list	*aux;
	t_list	*tmp;

	tmp = NULL;
	aux = lists->b;
	if (lists->b != NULL && lists->b->next != NULL)
	{
		while (aux->next->next != NULL)
			aux = aux->next;
		tmp = ft_lstlast(lists->b);
		tmp->next = lists->b;
		lists->b = tmp;
		aux->next = NULL;
	}
	lists->s = ft_strjoin(lists->s, "rrb\n");
}
