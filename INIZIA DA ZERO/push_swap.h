/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:59 by negambar          #+#    #+#             */
/*   Updated: 2024/05/23 12:38:03 by negambar         ###   ########.fr       */
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
	int				cost;
	bool			middle;
	int				index;
	bool			flag;
	struct t_struct	*next;
	struct t_struct	*prev;
}	stack;

stack	*get_stack_bottom(stack *stack);
stack	*get_stack_before_bottom(stack *s);
int		sorted_stack(stack *s, int size);
void	cost(stack *a, int size);
void	lis_sort(stack **a, stack **b, int *dup);

void	five(stack **a, stack **b);
void	four(stack **a, stack **b);

void	add_nodes(long num, stack **a);
void	tail_add(long n, stack **a);
int 	check_number(char *str);
int		ft_atoimdf(const char *nptr);
int		ft_isdigit(char *s);
void	fterror(int i);
int		dups(int *dup, int end);
void	fill_stack_a(char **av, int size, stack *a);
void	indexes(stack *a, int size);
void	tiny(stack **a, stack **b);
int		low_value(stack *a);

void	swap(stack *a, stack *b, char c);

void	rotate(stack **stack);
void	do_ra(stack **stacka);
void	do_rb(stack **stackb);

void	rrotate(stack **s);
void	do_rra(stack **stacka);
void	do_rrb(stack **stackb);

void	push(stack **src, stack **dest);
void	do_pa(stack **from_b, stack **to_a);
void	do_pb(stack **from_a, stack **to_b);

void	push_swap(stack **a, stack **b, int ac);
int		nb_abs(int n);
int		tallest(stack *a);
int		sorted(int *dup, int end);
void	free_stack(stack **s);
int		get_stack_size(stack *s);

void	ft_lstclear(stack **lst);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);
void	ft_lstadd_front(stack **lst, stack *new);
int		ft_lstsize(stack *lst);
void	ft_lstadd_back(stack **lst, stack *new);
void	ft_lstdelone(stack *lst);
void	ft_lstiter(stack *lst, void (*f)(void *));


/* TEST */
void	make_list(stack *a, stack *b);


#endif