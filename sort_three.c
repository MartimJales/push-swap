/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:43:47 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 16:38:03 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top(t_stacks *lists)
{
	return (((t_elem *)(lists->a->content))->index > \
	((t_elem *)(lists->a->next->content))->index);
}

int	check_mid(t_stacks *lists)
{
	return (((t_elem *)(lists->a->next->content))->index > \
	((t_elem *)(lists->a->next->next->content))->index);
}

int	check_bot(t_stacks *lists)
{
	return (((t_elem *)(lists->a->next->next->content))->index > \
	((t_elem *)(lists->a->content))->index);
}

void	sort_three(t_stacks *lists)
{
	int	top;
	int	mid;
	int	bot;

	top = check_top(lists);
	mid = check_mid(lists);
	bot = check_bot(lists);
	if (top && !mid && bot)
		swap_a(lists);
	else if (top && mid && !bot)
	{
		swap_a(lists);
		reverse_a(lists);
	}
	else if (top && !mid && !bot)
		rotate_a(lists);
	else if (!top && mid && bot)
	{
		swap_a(lists);
		rotate_a(lists);
	}
	else if (!top && mid && !bot)
		reverse_a(lists);
}
