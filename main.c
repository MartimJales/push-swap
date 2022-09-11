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
        printf("VALIDO\n");
        lists = create_stacks(argc, argv);
        print_stacks(*lists);
        reverse_a(lists);
        print_stacks(*lists);
    }
    else
        printf("INVALIDO\n");
    return (0);
}
