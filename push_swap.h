/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:47:25 by mjales            #+#    #+#             */
/*   Updated: 2023/02/01 18:59:01 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

//Adicionar uma estrutura com infos da stack ou colocar isso na t_stacks

typedef struct t_elem{
	int	index;
	int	value;
	int	chunk;
}t_elem;

typedef struct t_stacks{
	struct s_list	*a;
	struct s_list	*b;
	int				min_index_a;
	int				min_index_b;
	int				max_index_a;
	int				max_index_b;
	char			*s;
}t_stacks;

// Valid Input
int			valid_input(int argc, char *argv[]);
int			isinteger(char *s);
// Create t_stacks
t_list		*create_list(int argc, char *argv[], int arr[]);
t_stacks	*create_stacks(int argc, char *argv[]);
void		print_stacks(t_stacks lists);
void		index_list(t_list *list, int arr[], int n);
// Moves
void		swap_a(t_stacks *lists);
void		swap_b(t_stacks *lists);
void		push_a(t_stacks *lists);
void		push_b(t_stacks *lists);
void		rotate_a(t_stacks *lists);
void		rotate_b(t_stacks *lists);
void		reverse_a(t_stacks *lists);
void		reverse_b(t_stacks *lists);
//Sort F	unctions
void		sort_two(t_stacks *lists);
void		sort_three(t_stacks *lists);
void		sort_five(t_stacks *lists);
void		sort_hundred(t_stacks *lists, int num_chunks);
void		sort_many(t_stacks *lists, int num_chunks);
//Auxili	ar functions
void		update_indexs(t_stacks *lists);
t_elem		best_pos(t_list *lst, int index, int min, int max);
void		insert_in_a(t_stacks *lists);
void		insert_in_b(t_stacks *lists);
void		insert_in_order(t_stacks *lists, char stacks);
void		change_stack_a(t_stacks *lists, int chunks);
void		update_chunks(t_stacks *lists, int chunks);
int			best_move(t_stacks *tmp);

#endif
