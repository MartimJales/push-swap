/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:38:20 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 17:21:03 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_aux(t_stacks *lists, int j, t_elem moves, int chunks)
{
	if (j < chunks && moves.index < moves.value)
		while (((t_elem *)lists->a->content)->chunk != j)
			rotate_a(lists);
	else if (j < chunks)
		while (((t_elem *)lists->a->content)->chunk != j)
			reverse_a(lists);
}

void	change_stack_a(t_stacks *lists, int chunks)
{
	t_list	*tmp;
	t_elem	index;
	t_elem	moves;

	index.value = -1;
	moves.index = 0;
	while (!moves.index && ++index.value < chunks)
	{
		tmp = lists->a;
		index.index = 0;
		while (tmp && index.index++)
		{
			if (((t_elem *)tmp->content)->chunk == index.value)
			{
				if (!moves.index)
					moves.index = index.index;
				moves.value = ft_lstsize(lists->a) - index.index;
			}
			tmp = tmp->next;
		}
	}
	change_aux(lists, index.value, moves, chunks);
}

void	update_chunks(t_stacks *lists, int chunks)
{
	int		num;
	t_list	*tmp;

	tmp = lists->a;
	num = (int)(ft_lstsize(lists->a) / chunks);
	while (tmp)
	{
		((t_elem *)(tmp->content))->chunk = \
		((t_elem *)(tmp->content))->index / num;
		tmp = tmp->next;
	}
}

void	sort_hundred(t_stacks *lists, int num_chunks)
{
	t_elem	aux_index;

	update_chunks(lists, num_chunks);
	while (ft_lstsize(lists->a) > 1)
	{
		change_stack_a(lists, num_chunks);
		push_b(lists);
	}
	while (ft_lstsize(lists->b) > 0)
	{
		insert_in_order(lists, 'a');
	}
	aux_index = best_pos(lists->a, -1, lists->min_index_a, lists->max_index_a);
	if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
		while (((t_elem *)lists->a->content)->index != aux_index.value)
			rotate_a(lists);
	else
		while (((t_elem *)lists->a->content)->index != aux_index.value)
			reverse_a(lists);
}
