/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:38:20 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 15:31:03 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
