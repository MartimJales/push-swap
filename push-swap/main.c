/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:12:41 by mjales            #+#    #+#             */
/*   Updated: 2022/09/11 16:30:04 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
    stacks *lists;
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
        else if (argc - 1 <= 5)
            sort_five(lists);
        else if (argc - 1 <= 100)
            sort_five(lists);
        else if (argc - 1 <= 500)
            sort_many(lists);
    }
    else
    {
        printf("Error no input\n");
        return (0);
    }
    // print_stacks(*lists);
    printf("%s", lists->s);
    return (0);
}

void print_stacks(stacks lists)
{
	printf("A: ");
     while (lists.a)
     {
        printf("{%d,%d} ", ((elem *)(lists.a->content))->value, ((elem *)(lists.a->content))->index);
        lists.a = lists.a->next;
     }
	 printf("\nB: ");
     while (lists.b)
     {
        printf("{%d,%d} ", ((elem *)(lists.b->content))->value, ((elem *)(lists.b->content))->index);
        lists.b = lists.b->next;
     }
	 printf("\nS: %s\n", lists.s);
    //  printf("min A = %d\n", lists.min_index_a);
    //  printf("max A = %d\n", lists.max_index_a);
    //  printf("min B = %d\n", lists.min_index_b);
    //  printf("max B = %d\n", lists.max_index_b);
}