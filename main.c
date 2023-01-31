/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:12:41 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 17:21:32 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
    t_stacks *lists;

    if (argc == 1)
        printf("\n");
    else if (valid_input(argc, argv))
    {
        lists = create_stacks(argc, argv);
        if (!argc - 1 == 1)
            return (0);
        if (argc - 1 == 2)
            sort_two(lists);
        else if (argc - 1 == 3)
            sort_three(lists);
        else if (argc - 1 <= 20)
            sort_five(lists);
        else if (argc - 1 <= 100)
            sort_hundred(lists, 6);
        else if (argc - 1 <= 50000)
            sort_many(lists, 11);
    }
    else
    {
        printf("Error no input\n");
        return (0);
    }
    printf("%s", lists->s);
    return (0);
}

void print_stacks(t_stacks lists)
{
	printf("A: ");
     while (lists.a)
     {
        printf("{%d,%d}[%d]\n", ((t_elem *)(lists.a->content))->value, ((t_elem *)(lists.a->content))->index, ((t_elem *)(lists.a->content))->chunk);
        lists.a = lists.a->next;
     }
	 printf("\nB: ");
     while (lists.b)
     {
        printf("{%d,%d} ", ((t_elem *)(lists.b->content))->value, ((t_elem *)(lists.b->content))->index);
        lists.b = lists.b->next;
     }
	 printf("\nS: %s\n", lists.s);
    //  printf("min A = %d\n", lists.min_index_a);
    //  printf("max A = %d\n", lists.max_index_a);
    //  printf("min B = %d\n", lists.min_index_b);
    //  printf("max B = %d\n", lists.max_index_b);
}

void insert_in_order(t_stacks *lists, char stack)
{
    t_elem aux_index;

    if (stack == 'a')
    {
        if (lists->a)
            aux_index = best_pos(lists->a, ((t_elem *)lists->b->content)->index, lists->min_index_a, lists->max_index_a);
        if (lists->a && aux_index.index < ft_lstsize(lists->a) - aux_index.index)
            while (((t_elem *)lists->a->content)->index != aux_index.value)
                rotate_a(lists);
        else if (lists->a)
            while (((t_elem *)lists->a->content)->index != aux_index.value)
                reverse_a(lists);
        push_a(lists);
    }
    else if (stack == 'b')
    {
        if (lists->b)
            aux_index = best_pos(lists->b, ((t_elem *)lists->a->content)->index, lists->min_index_b, lists->max_index_b);
        if (lists->b && aux_index.index < ft_lstsize(lists->b) - aux_index.index)
            while (((t_elem *)lists->b->content)->index != aux_index.value)
                rotate_b(lists);
        else if (lists->b)
            while (((t_elem *)lists->b->content)->index != aux_index.value)
                reverse_b(lists);
        push_b(lists);
    }
    else
        printf("deu um char errado na insert_order\n");
}
