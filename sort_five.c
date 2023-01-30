#include "push_swap.h"

void sort_five(stacks *lists)
{
    elem aux_index;

    push_b(lists);
    while(ft_lstsize(lists->a) > 3)
        insert_in_order(lists, 'b');
    sort_three(lists);
    while (lists->b)
    {
        insert_in_order(lists, 'a');
    }
    aux_index = find_best_pos(lists->a, -1, lists->min_index_a, lists->max_index_a);
    if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
        while (((elem *)lists->a->content)->index != aux_index.value)
            rotate_a(lists);
    else
        while (((elem *)lists->a->content)->index != aux_index.value)
            reverse_a(lists);
}



