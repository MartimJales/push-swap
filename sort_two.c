#include "push_swap.h"

void sort_two(stacks *lists)
{
    int top;
    int bottom;

    top = ((elem *)(lists->a->content))->index;
    bottom = ((elem *)(lists->a->next->content))->index;

    if (top > bottom)
        swap_a(lists);        
}