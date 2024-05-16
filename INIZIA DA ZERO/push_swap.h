/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:59 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 11:57:40 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  include <unistd.h>
#  include <limits.h>
#  include "libft/libft.h"
#  include "printf/ft_printf.h"
#  include <stdio.h>
#  include <stdbool.h>

typedef struct t_struct
{
	int				value;
	bool			middle;
	int				index;
	struct t_struct	*next;
	struct t_struct	*prev;
}	stack;

void	five(stack *a, stack *b, int size);
void	add_nodes(long num, stack **a);
void	tail_add(long n, stack **a);
int 	check_number(char *str);
int		ft_atoimdf(const char *nptr);
int		ft_isdigit(char *s);
void	fterror(int i);
int		dups(int *dup, int end);
void	fill_stack_a(char **av, int size, stack *a);
void	indexes(stack *a, int size);
void	tiny(stack *a, stack *b, int size);
int		low_value(stack *a);
//void	get_target_pos(stack *a);

void	swap(stack *a, stack *b, char c);
void	rotate(stack **a, stack **b, int size, char c);
void	rrotate(stack **a, stack **b, int size, char c);
//void	push(stack **a,, char c);
void	push(stack **to, stack **from, int size);
// void	do_pa(stack **a, stack **b);
// void	do_pb(stack **a, stack **b);

void	push_swap(stack *a, stack *b, int ac);
int		nb_abs(int n);
int		tallest(stack *a);
int		sorted(int *dup, int end);

//int		get_low_indpos(stack *s);
//void	do_cheap(stack *a);
//void	get_cost(stack *a, int ac);
int		get_stack_size(stack **a);

void	ft_lstclear(stack **lst);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);
void	ft_lstadd_front(stack **lst, stack *new);
int		ft_lstsize(stack *lst);
void	ft_lstadd_back(stack **lst, stack *new);
void	ft_lstdelone(stack *lst);
void	ft_lstiter(stack *lst, void (*f)(void *));

#endif