/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:12:41 by mjales            #+#    #+#             */
/*   Updated: 2022/09/06 15:12:41 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
    int stacks;

    stacks = 0;
    if (argc == 1)
        printf("\n");
    else if (valid_input(argc, argv))
    {
        printf("VALIDO\n");
        //stacks = c   reate_stacks(argc, argv);
        //organize_stack(stacks)
    }
    else
        printf("INVALIDO\n");
    return (stacks);
}
