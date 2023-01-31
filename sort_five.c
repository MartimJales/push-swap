/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:45:44 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 17:29:06 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stacks *lists)
{
	t_elem	aux_index;

	push_b(lists);
	while (ft_lstsize(lists->a) > 3)
		push_b(lists);
	sort_three(lists);
	while (lists->b)
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
