#include "push_swap.h"

void insert_in_order(stacks *lists, char stack)
{
    elem aux_index;

    if (stack == 'a')
    {
        aux_index = find_best_pos(lists->a, ((elem *)lists->b->content)->index, lists->min_index_a, lists->max_index_a);
        if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
            while (((elem *)lists->a->content)->index != aux_index.value)
                rotate_a(lists); 
        else 
            while (((elem *)lists->a->content)->index != aux_index.value)
                reverse_a(lists);
        push_a(lists);
    }
    else if (stack == 'b')
    {
        aux_index = find_best_pos(lists->b, ((elem *)lists->a->content)->index, lists->min_index_b, lists->max_index_b);
        if (aux_index.index < ft_lstsize(lists->b) - aux_index.index)
            while (((elem *)lists->b->content)->index != aux_index.value)
                rotate_b(lists); 
        else 
            while (((elem *)lists->b->content)->index != aux_index.value)
                reverse_b(lists);
        push_b(lists);
    }
    else 
        printf("deu um char errado na insert_order\n");
}

void sort_five(stacks *lists)
{
    while(ft_lstsize(lists->a) > 3)
        push_b(lists);
    sort_three(lists);
    while (lists->b)
    {
        insert_in_order(lists, 'a');
    }
    while(((elem *)lists->a->content)->index != lists->min_index_a)
        rotate_a(lists);
}



