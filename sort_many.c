#include "push_swap.h"

void sort_many(stacks *lists)
{
    elem aux_index;
    int num_chunks = 11;

    (void)aux_index;
    update_chunks(lists, num_chunks);
    while(ft_lstsize(lists->a) > 1){
        change_stack_a(lists, num_chunks);
        push_b(lists);
        // insert_in_order(lists, 'b');
    }
     while(ft_lstsize(lists->b) > 0){
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
