/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:29:29 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 18:09:24 by mjales           ###   ########.fr       */
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

int	in_between(int min, int index, int max)
{
	return (min < index && index < max);
}

void aux_pos()
{
	
}

t_elem	best_pos(t_list *lst, int index, int min, int max)
{
	t_list	*tmp;
	t_elem	aux_index;

	tmp = lst;
	aux_index.index = 0;
	aux_index.value = 0;
	if (index < min || index > max)
	{
		while (((t_elem *)tmp->content)->index != min)
		{
			aux_index.index++;
			tmp = tmp->next;
		}
	}
	else
	{
		if (!in_between(((t_elem *)ft_lstlast(tmp)->content)->index, index, \
		((t_elem *)tmp->content)->index))
		{
			while (tmp)
			{
				if (in_between(((t_elem *)tmp->content)->index, index, \
				((t_elem *)tmp->next->content)->index))
				{
					tmp = tmp->next;
					aux_index.index++;
					break ;
				}
				tmp = tmp->next;
				aux_index.index++;
			}
		}
	}
	aux_index.value = ((t_elem *)tmp->content)->index;
	return (aux_index);
}
