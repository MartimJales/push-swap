/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:12:41 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 15:33:30 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_stacks	*lists;

	lists = create_stacks(argc, argv);
	if (argc - 1 == 1)
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
	printf("%s", lists->s);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	else if (valid_input(argc, argv))
		return (push_swap(argc, argv));
	else
		write(2, "Error\n", 6);
	return (0);
}

void	insert_in_order(t_stacks *lists, char stack)
{
	t_elem	aux;

	if (stack == 'a')
	{
		if (lists->a)
		{
			aux = best_pos(lists->a, ((t_elem *)lists->b->content)->index, \
			lists->min_index_a, lists->max_index_a);
		}
		if (lists->a && aux.index < ft_lstsize(lists->a) - aux.index)
			while (((t_elem *)lists->a->content)->index != aux.value)
				rotate_a(lists);
		else if (lists->a)
			while (((t_elem *)lists->a->content)->index != aux.value)
				reverse_a(lists);
		push_a(lists);
	}
}
	// else if (stack == 'b')
	// {
	// 	if (lists->b)
	// 		aux = best_pos(lists->b, ((t_elem *)lists->a->content)->index,
	// 		lists->min_index_b, lists->max_index_b);
	// 	if (lists->b && aux.index < ft_lstsize(lists->b) - aux.index)
	// 		while (((t_elem *)lists->b->content)->index != aux.value)
	// 			rotate_b(lists);
	// 	else if (lists->b)
	// 		while (((t_elem *)lists->b->content)->index != aux.value)
	// 			reverse_b(lists);
	// 	push_b(lists);
	// }
	// else
	// 	printf("deu um char errado na insert_order\n");

// void	print_stacks(t_stacks lists)
// {
// 	printf("A: ");
// 	while (lists.a)
// 	{
// 		lists.a = lists.a->next;
// 	}
// 	printf("\nB: ");
// 	while (lists.b)
// 	{
// 		printf("{%d,%d} ", ((t_elem *)(lists.b->content))->value,
// ((t_elem *)(lists.b->content))->index);
// 		lists.b = lists.b->next;
// 	}
// 	printf("\nS: %s\n", lists.s);
// }
