/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:59 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 13:12:03 by negambar         ###   ########.fr       */
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
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
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
void	sort(stack **stack_a, stack **stack_b);
int		get_lowest_index_position(stack **a);
void	get_target_position(stack **a, stack **b);

void	get_cost(stack **stack_a, stack **stack_b);
void	do_cheapest_move(stack **stack_a, stack **stack_b);

void	add_nodes(long num, stack **a);
void	tail_add(long n, stack **a);
int 	check_number(char *str);
int		ft_atoimdf(const char *nptr);
int		ft_isdigit(char *s);
void	fterror(int i);
int		dups(int *dup, int end);
void	fill_stack_a(char **av, int size, stack *a);
void	indexes(stack *a, int size);
void	tiny(stack **a);
int		low_value(stack *a);


void	swap(stack *a, stack *b, char c);
void post_cost(stack *a, stack *a2);

void	rotate(stack **stack);
void	do_ra(stack **stacka);
void	do_rb(stack **stackb);
void	do_rr(stack **stacka, stack **stackb);

void	rrotate(stack **s);
void	do_rra(stack **stacka);
void	do_rrb(stack **stackb);
void do_rrr(stack **stack_a, stack **stack_b);

void	push(stack **src, stack **dest);
void	do_pa(stack **from_b, stack **to_a);
void	do_pb(stack **from_a, stack **to_b);

void	push_swap(stack **a, stack **b, int ac);
int		nb_abs(int n);
int		tallest(stack *a);
int		sorted(int *dup, int end);
void	free_stack(stack **s);
int		get_stack_size(stack *s);
int		is_sorted(stack *a);
int		get_target(stack **a, int b_idx, int target_idx, int target_pos);
void	do_move(stack **a, stack **b, int cost_a, int cost_b);

void	ft_lstclear(stack **lst);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);
void	ft_lstadd_front(stack **lst, stack *new);
int		ft_lstsize(stack *lst);
void	ft_lstadd_back(stack **lst, stack *new);
void	ft_lstdelone(stack *lst);
void	ft_lstiter(stack *lst, void (*f)(void *));


/* TEST */
void	make_list(stack **a, stack **b);


#endif