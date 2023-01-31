/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:05:34 by mjales            #+#    #+#             */
/*   Updated: 2023/01/31 14:00:27 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

t_list *create_list(int argc, char *argv[], int arr[])
{
    t_list *lst;
    t_list *new;
	t_elem *element;
    int	i;
	int j;

	lst = NULL;
	i = 0;
	j = 0;
	while (i++ < argc - 1)
	{
		element = malloc(sizeof(t_elem));
		element->index = -1;
        element->value = ft_atoi(argv[i]);
		element->chunk = -1;
		arr[j] = element->value;
		j++;
        new = ft_lstnew((void *)element);
        ft_lstadd_back(&lst, new);
	}
    return (lst);
}

void index_list(t_list *list, int arr[], int n)
{
	int i;

	while(list)
	{
		i = -1;
		while(++i < n)
			if (arr[i] == ((t_elem *)(list->content))->value)
			{
				((t_elem *)(list->content))->index = i;
			}
 		list = list->next;
	}
}

t_stacks *create_stacks(int argc, char *argv[])
{
	t_stacks *lists;
	t_list *a;
	t_list *b;
	char *s;
	int arr[argc - 1];

	lists = malloc(sizeof(t_stacks));
	s = malloc(100);
	ft_memset(s, 0, 100);
	a = create_list(argc, argv, arr);
	bubbleSort(arr, argc - 1);
	index_list(a, arr, argc - 1);
    b = NULL;
	lists->a = a;
	lists->b = b;
	update_indexs(lists);
	lists->s = s;
	return (lists);
}
