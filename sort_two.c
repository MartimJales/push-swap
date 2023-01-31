/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:40:28 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 14:40:51 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *lists)
{
	int	top;
	int	bottom;

	top = ((t_elem *)(lists->a->content))->index;
	bottom = ((t_elem *)(lists->a->next->content))->index;
	if (top > bottom)
		swap_a(lists);
}
