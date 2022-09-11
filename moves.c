/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movees.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:30:02 by mjales            #+#    #+#             */
/*   Updated: 2022/09/11 17:16:49 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(stacks *lists)
{
	int aux;

	aux = (*lists).a->next->content;
	(*lists).a->next->content = (*lists).a->content;
	(*lists).a->content = aux;
	printf("sa\n");
	// I need to add strjoin to this
}

void swap_b(stacks *lists)
{
	int aux;

	aux = (*lists).b->next->content;
	(*lists).b->next->content = (*lists).b->content;
	(*lists).b->content = aux;
	printf("sb\n");
	// I need to add strjoin to this
}

void push_a(stacks *lists)
{
	t_list *new;

	new = NULL;
	if (lists->b != NULL)
	{
		new = lists->b->next;
		lists->b->next = lists->a;
		lists->a = lists->b;
		lists->b = new;
	}
	printf("pa\n");
}

void push_b(stacks *lists)
{
	t_list *new;

	new = NULL;
	if (lists->a != NULL)
	{
		new = lists->a->next;
		lists->a->next = lists->b;
		lists->b = lists->a;
		lists->a = new;
	}
	printf("pb\n");
}

void rotate_a(stacks *lists)
{
	t_list *aux;

	aux = NULL;
	if (lists->a != NULL && lists->a->next != NULL)
	{
		aux = ft_lstlast(lists->a);
		aux->next = lists->a;
		lists->a = lists->a->next;
		aux->next->next = NULL;
	}
	printf("ra\n");
}

void rotate_b(stacks *lists)
{
	t_list *aux;

	aux = NULL;
	if (lists->b != NULL && lists->b->next != NULL)
	{
		aux = ft_lstlast(lists->b);
		aux->next = lists->b;
		lists->b = lists->b->next;
		aux->next->next = NULL;
	}
	printf("rb\n");
}

void reverse_a(stacks *lists)
{
	t_list *aux;
	t_list *tmp;

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
	printf("rra\n");
}


