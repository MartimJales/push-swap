/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:05 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 15:32:41 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_chunk(t_stacks *lists, int j, t_elem moves, int chunks)
{
	if (j < chunks && moves.index < moves.value)
		while (((t_elem *)lists->a->content)->chunk != j)
			rotate_a(lists);
	else if (j < chunks)
		while (((t_elem *)lists->a->content)->chunk != j)
			reverse_a(lists);
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
		while (tmp)
		{
			if (((t_elem *)tmp->content)->chunk == index.value)
			{
				if (!moves.index)
					moves.index = index.index;
				moves.value = ft_lstsize(lists->a) - index.index;
			}
			index.index++;
			tmp = tmp->next;
		}
	}
	rotate_chunk(lists, index.value, moves, chunks);
}
