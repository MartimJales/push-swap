/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:30:02 by mjales            #+#    #+#             */
/*   Updated: 2023/01/30 12:48:05 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(stacks *lists)
{
	long aux;

	aux = (long)(*lists).a->next->content;
	(*lists).a->next->content = (*lists).a->content;
	(*lists).a->content = (void *)aux;
	// printf("sa\n");
	lists->s = ft_strjoin(lists->s, "sa\n");
	// print_stacks(*lists);
	// I need to add strjoin to this
}

void swap_b(stacks *lists)
{
	long aux;

	aux = (long)(*lists).b->next->content;
	(*lists).b->next->content = (*lists).b->content;
	(*lists).b->content = (void *)aux;
	// printf("sb\n");
	lists->s = ft_strjoin(lists->s, "sb\n");
	// print_stacks(*lists);
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
	update_indexs(lists);
	// printf("pa\n");
	lists->s = ft_strjoin(lists->s, "pa\n");
	// print_stacks(*lists);
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
	update_indexs(lists);
	// printf("pb\n");
	lists->s = ft_strjoin(lists->s, "pb\n");
	// print_stacks(*lists);
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
	// printf("ra\n");
	lists->s = ft_strjoin(lists->s, "ra\n");
	// print_stacks(*lists);
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
	// printf("rb\n");
	lists->s = ft_strjoin(lists->s, "rb\n");
	// print_stacks(*lists);
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
	// printf("rra\n");
	lists->s = ft_strjoin(lists->s, "rra\n");
	// print_stacks(*lists);
}

void reverse_b(stacks *lists)
{
	t_list *aux;
	t_list *tmp;

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
	// printf("rrb\n");
	lists->s = ft_strjoin(lists->s, "rrb\n");
	// print_stacks(*lists);
}
