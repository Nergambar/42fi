/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:59 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 16:14:53 by negambar         ###   ########.fr       */
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
	/*int				pos;
	int				target;
	int				cost_a;
	int				cost_b; */
	int				index;
	struct t_struct	*next;
	struct t_struct	*prev;
}	stack;

typedef struct s_struct
{
	struct t_struct *a;
	struct t_struct *b;
} list;

void	five(list *one);
void	add_nodes(long num, list *one);
void	tail_add(list **one);
int 	check_number(char *str);
int		ft_atoimdf(const char *nptr);
int		ft_isdigit(char *s);
void	fterror(int i);
int		dups(int *dup, int end);

void	fill_stack_a(int ac, char **av, list *one);
void	indexes(list *one);
void	tiny(list *one);
int		low_value(list *one);
//void	get_target_pos(list *one);

void	swap(list *one, char c);
void	rotate(list **one, char c);
void	rrotate(list **one, char c);
//void	push(list **one,, char c);
void	push(list **list_to, list **list_from);
void	do_pa(list *one);
void	do_pb(list *one);

void	push_swap(list *one, int ac);
int		nb_abs(int n);
int		tallest(list *one);
int		sorted(int *dup, int end);

//int		get_low_indpos(list *s);
//void	do_cheap(list *one);
//void	get_cost(list *one, int ac);
int		get_stack_size(list *one);

void	ft_lstclear(stack **lst);
stack	*ft_lstnew(int content);
void	ft_lstlast(list *lst);
void	ft_lstadd_front(stack **lst, stack *new);
int		ft_lstsize(stack *lst);
void	ft_lstadd_back(list **lst, list *new);
void	ft_lstdelone(stack *lst);
void	ft_lstiter(stack *lst, void (*f)(void *));

#endif