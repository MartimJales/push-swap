/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:47:25 by mjales            #+#    #+#             */
/*   Updated: 2022/09/10 15:19:50 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int		        content;
	struct s_list	*next;
}	t_list;

typedef struct stacks{
  struct s_list *a;
  struct s_list *b;
  char *s;
}
stacks;

int valid_input(int argc, char* argv[]);
int isinteger(char *s);
int ft_isdigit(int c);
int	ft_atoi(const char *str);
t_list *create_list(int argc, char *argv[]);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
stacks *create_stacks(int argc, char *argv[]);
void print_stacks(stacks *lists);

#endif
