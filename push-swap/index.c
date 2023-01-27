#include "push_swap.h"

int get_min_index(t_list *lst)
{
    int i;

    if (!lst)
        return (-1);
    i = ((elem *)lst->content)->index;
    while(lst) {
        if (i > ((elem *)lst->content)->index)
            i = ((elem *)lst->content)->index;
        lst = lst->next;
    }
    return (i);
}

int get_max_index(t_list *lst)
{
    int i;

    if (!lst)
        return (-1);
    i = ((elem *)lst->content)->index;
    while(lst) {
        if (i < ((elem *)lst->content)->index)
            i = ((elem *)lst->content)->index;
        lst = lst->next;
    }
    return (i);
}


void update_indexs(stacks *lists)
{
	lists->min_index_a = get_min_index(lists->a);
	lists->min_index_b = get_min_index(lists->b);
	lists->max_index_a = get_max_index(lists->a);
	lists->max_index_b = get_max_index(lists->b);
}

// Change this functions to return an index where you will insert the new element
// Receive the list you want to insert and the index of the element you want yo add
int in_between(int min, int index, int max)
{
    return (min < index && index < max);
}

// Pensar melhor nesta funcao porque a lista pode nao estar ordenada
// Nesse caso desordenado esta funcao e inutil
elem find_best_pos(t_list *lst, int index, int min, int  max)
{
    t_list *tmp;
    elem aux_index;
    
    tmp = lst;
    aux_index.index = 0;
    aux_index.value = 0;
    if (index < min || index > max)
        while(((elem *)tmp->content)->index != min)
        {
            aux_index.index++;
            tmp = tmp->next;
        }
    else
    {
        if (!in_between(((elem *)ft_lstlast(tmp)->content)->index, index, ((elem *)tmp->content)->index))
            while(tmp)
            {
                if (in_between(((elem *)tmp->content)->index, index, ((elem *)tmp->next->content)->index))
                {
                    tmp = tmp->next;
                    aux_index.index++;
                    break;
                }
                tmp = tmp->next;
                aux_index.index++;
            }
    }
    aux_index.value = ((elem *)tmp->content)->index;
    return (aux_index);
}


int find_best_move(stacks *tmp)
{
    swap_a(tmp);
    return 1;
}