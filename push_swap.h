/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:47:25 by mjales            #+#    #+#             */
/*   Updated: 2023/01/30 18:13:43 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

//Adicionar uma estrutura com infos da stack ou colocar isso na stacks

typedef struct elem{
  int index;
  int value;
  int chunk;
}
elem;

typedef struct stacks{
  struct s_list *a;
  struct s_list *b;
  int min_index_a;
  int min_index_b;
  int max_index_a;
  int max_index_b;
  char *s;
}
stacks;

// Valid Input
int valid_input(int argc, char* argv[]);
int isinteger(char *s);
// Create stacks
t_list *create_list(int argc, char *argv[], int arr[]);
stacks *create_stacks(int argc, char *argv[]);
void print_stacks(stacks lists);
void index_list(t_list *list, int arr[], int n);
// Moves
void swap_a(stacks *lists);
void swap_b(stacks *lists);
void push_a(stacks *lists);
void push_b(stacks *lists);
void rotate_a(stacks *lists);
void rotate_b(stacks *lists);
void reverse_a(stacks *lists);
void reverse_b(stacks *lists);
//Sort Functions
void sort_two(stacks *lists);
void sort_three(stacks *lists);
void sort_five(stacks *lists);
void sort_hundred(stacks *lists);
void sort_many(stacks *lists);
//Auxiliar functions
void update_indexs(stacks *lists);
elem find_best_pos(t_list *lst, int index, int min, int  max);
int find_best_move(stacks *tmp);
void insert_in_order(stacks *lists, char stack);

#endif
