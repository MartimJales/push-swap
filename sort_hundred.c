#include "push_swap.h"

void change_stack_a(stacks *lists, int chunks)
{
    int i, j;
    int max_rot;
    int max_rev;
    t_list *tmp;

    j = -1;
    max_rot = 0;
    while (!max_rot && ++j < chunks)
    {
        tmp = lists->a;
        i = 0;
        while (tmp){
            if (((elem *)tmp->content)->chunk == j){
                if (!max_rot)
                    max_rot = i;
                max_rev = ft_lstsize(lists->a) - i;
            }
            i++;
            tmp = tmp->next;
        }
    }
    if (j < chunks && max_rot < max_rev)
        while (((elem *)lists->a->content)->chunk != j)
                rotate_a(lists);
    else if (j < chunks)
        while (((elem *)lists->a->content)->chunk != j)
            reverse_a(lists);
}

void update_chunks(stacks *lists, int chunks)
{
    int num;
    t_list *tmp = lists->a;

    num = (int)(ft_lstsize(lists->a) / chunks);
    while(tmp)
    {
        ((elem *)(tmp->content))->chunk = ((elem *)(tmp->content))->index / num;
        tmp = tmp->next;
    }
}

void sort_hundred(stacks *lists)
{
    elem aux_index;
    int num_chunks = 5;

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
    printf("index wanted = %d\n", aux_index.value);
    if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
        while (((elem *)lists->a->content)->index != aux_index.value)
            rotate_a(lists);
    else
        while (((elem *)lists->a->content)->index != aux_index.value)
            reverse_a(lists);

}
