/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:30:02 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 17:29:20 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *lists)
{
	long	aux;

	aux = (long)(*lists).a->next->content;
	(*lists).a->next->content = (*lists).a->content;
	(*lists).a->content = (void *)aux;
	lists->s = ft_strjoin(lists->s, "sa\n");
}

void	push_a(t_stacks *lists)
{
	t_list	*new;

	new = NULL;
	if (lists->b != NULL)
	{
		new = lists->b->next;
		lists->b->next = lists->a;
		lists->a = lists->b;
		lists->b = new;
	}
	update_indexs(lists);
	lists->s = ft_strjoin(lists->s, "pa\n");
}

void	rotate_a(t_stacks *lists)
{
	t_list	*aux;

	aux = NULL;
	if (lists->a != NULL && lists->a->next != NULL)
	{
		aux = ft_lstlast(lists->a);
		aux->next = lists->a;
		lists->a = lists->a->next;
		aux->next->next = NULL;
	}
	lists->s = ft_strjoin(lists->s, "ra\n");
}

void	reverse_a(t_stacks *lists)
{
	t_list	*aux;
	t_list	*tmp;

	tmp = NULL;
	aux = lists->a;
	if (lists->a != NULL && lists->a->next != NULL)
	{
		while (aux->next->next != NULL)
			aux = aux->next;
		tmp = ft_lstlast(lists->a);
		tmp->next = lists->a;
		lists->a = tmp;
		aux->next = NULL;
	}
	lists->s = ft_strjoin(lists->s, "rra\n");
}
