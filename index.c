/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:29:29 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 11:04:14 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = ((t_elem *)lst->content)->index;
	while (lst)
	{
		if (i > ((t_elem *)lst->content)->index)
			i = ((t_elem *)lst->content)->index;
		lst = lst->next;
	}
	return (i);
}

int	get_max_index(t_list *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = ((t_elem *)lst->content)->index;
	while (lst)
	{
		if (i < ((t_elem *)lst->content)->index)
			i = ((t_elem *)lst->content)->index;
		lst = lst->next;
	}
	return (i);
}

void	update_indexs(t_stacks *lists)
{
	lists->min_index_a = get_min_index(lists->a);
	lists->min_index_b = get_min_index(lists->b);
	lists->max_index_a = get_max_index(lists->a);
	lists->max_index_b = get_max_index(lists->b);
}
