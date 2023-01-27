#include "push_swap.h"

void sort_hundred(stacks *lists)
{
    elem aux_index;

    //Este loop tem que ser otimizado daqui para a frente, porque 
    //pode ser mais eficiente encontrar por reverse ou rotate
    while (lists->b)
    {
        aux_index = find_best_pos(lists->a, ((elem *)lists->b->content)->index, lists->min_index_a, lists->max_index_a);
        // printf("index esperado = %d\n", aux_index.value);
        // printf("moves para rotate = %d\n", aux_index.index);
        // printf("moves para reverse = %d\n", ft_lstsize(lists->a) - aux_index.index);
        if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
            while (((elem *)lists->a->content)->index != aux_index.value)
                rotate_a(lists); 
        else 
            while (((elem *)lists->a->content)->index != aux_index.value)
                reverse_a(lists);
        push_a(lists);
        if (((elem *)lists->a->content)->index == lists->max_index_a)
            rotate_a(lists);
        else if (((elem *)ft_lstlast(lists->a)->content)->index == lists->min_index_a)
            reverse_a(lists);
    }
    while(((elem *)lists->a->content)->index != lists->min_index_a)
        rotate_a(lists);
}