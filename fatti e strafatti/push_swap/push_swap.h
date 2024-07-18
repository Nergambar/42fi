/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:51:59 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:41:37 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				t_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack_value(int ac, char **av);
void		assign_index(t_stack *a, int size);

int			is_sorted(t_stack *stack);
void		tiny(t_stack **a);
void		sort(t_stack **a, t_stack **b);

int			get_lowest(t_stack **s);

void		get_cost(t_stack **a, t_stack **b);
void		do_cheapest_move(t_stack **a, t_stack **b);
void		get_target_pos(t_stack **a, t_stack **b);

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		do_sa(t_stack **a);
void		do_sb(t_stack **b);
void		do_ss(t_stack **a, t_stack **b);
void		do_pa(t_stack **a, t_stack **b);
void		do_pb(t_stack **a, t_stack **b);
void		do_ra(t_stack **a);
void		do_rb(t_stack **b);
void		do_rr(t_stack **a, t_stack **b);
void		do_rra(t_stack **a);
void		do_rrb(t_stack **b);
void		do_rrr(t_stack **a, t_stack **b);

t_stack		*get_bottom(t_stack *s);
t_stack		*get_before_bottom(t_stack *s);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **s, t_stack *new);
int			stack_size(t_stack	*stack);

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);

void		exit_error(int error);

int			correct(char **av, int ac);
int			ft_isdigit(char c);
int			nbstr_cmp(const char *s1, const char *s2);

char		**ft_split(char const *s, char c);
char		**mtx_dup(char **av);
void		free_mtx(char **av);
char		*ft_strdup(char *src);

#endif