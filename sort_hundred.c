#include "push_swap.h"

void change_stack_a(stacks *lists, int chunks)
{
    int i;
    int flag;
    int max_rot;
    int max_rev;
    t_list *tmp;

    i = 0;
    (void)i;
    flag = 0;
    while (chunks > -1)
    {
        tmp = lists->a;
        printf("===CHUNK %d===\n", chunks);
        while (tmp){
            if (((elem *)tmp->content)->chunk == chunks){
                if (!flag)
                    flag = 1;
                printf("{%d,%d}[%d]\n", ((elem *)(tmp->content))->value, ((elem *)(tmp->content))->index, ((elem *)(tmp->content))->chunk);
            }
            max_rot++;
            tmp = tmp->next;
        }
        chunks--;
        (void)max_rev;
    }
    (void)flag;
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

    update_chunks(lists, num_chunks);
    while(ft_lstsize(lists->a) > 0){
        change_stack_a(lists, num_chunks);
        printf("seg fault?\n");
        insert_in_order(lists, 'b');
    }
    aux_index = find_best_pos(lists->a, -1, lists->min_index_a, lists->max_index_a);
    if (aux_index.index < ft_lstsize(lists->a) - aux_index.index)
        while (((elem *)lists->a->content)->index != aux_index.value)
            rotate_a(lists);
    else
        while (((elem *)lists->a->content)->index != aux_index.value)
            reverse_a(lists);
}
