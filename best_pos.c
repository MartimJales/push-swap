/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:36 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 11:02:19 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_between(int min, int index, int max)
{
	return (min < index && index < max);
}

t_list	*aux_pos(t_list	*tmp, t_elem	*aux_index, int teste)
{
	if (!in_between(((t_elem *)ft_lstlast(tmp)->content)->index, \
	teste, ((t_elem *)tmp->content)->index))
	{
		while (tmp)
		{
			if (in_between(((t_elem *)tmp->content)->index, \
			teste, ((t_elem *)tmp->next->content)->index))
			{
				tmp = tmp->next;
				aux_index->index++;
				break ;
			}
			tmp = tmp->next;
			aux_index->index++;
		}
	}
	return (tmp);
}

t_elem	best_pos(t_list *lst, int teste, int min, int max)
{
	t_list	*tmp;
	t_elem	aux_index;

	tmp = lst;
	aux_index.index = 0;
	aux_index.value = 0;
	if (teste < min || teste > max)
	{
		while (((t_elem *)tmp->content)->index != min)
		{
			aux_index.index++;
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = aux_pos(tmp, &aux_index, teste);
	}
	aux_index.value = ((t_elem *)tmp->content)->index;
	return (aux_index);
}
