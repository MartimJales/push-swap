#include "push_swap.h"

void sort_three(stacks *lists)
{
    int top_middle;
    int middle_bottom;
    int bottom_top;
    // int top = ((elem *)(lists->a->content))->value;
    // int middle = ((elem *)(lists->a->next->content))->value;
    // int bottom = ((elem *)(lists->a->next->next->content))->value;

    top_middle = ((elem *)(lists->a->content))->index > ((elem *)(lists->a->next->content))->index;
    middle_bottom = ((elem *)(lists->a->next->content))->index > ((elem *)(lists->a->next->next->content))->index;
    bottom_top = ((elem *)(lists->a->next->next->content))->index > ((elem *)(lists->a->content))->index;

    // printf("SORT 3\n");
    // print_stacks(*lists);
    if (top_middle && !middle_bottom && bottom_top)
        swap_a(lists);        
    else if (top_middle && middle_bottom && !bottom_top)
    {
        swap_a(lists);
        reverse_a(lists);
    }        
    else if (top_middle && !middle_bottom && !bottom_top)
        rotate_a(lists);
    else if (!top_middle && middle_bottom && bottom_top)
    {
        swap_a(lists);
        rotate_a(lists);
    }
    else if (!top_middle && middle_bottom && !bottom_top)
        reverse_a(lists);
}