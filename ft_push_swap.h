/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 18:20:13 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;
typedef struct s_cost
{
	int		a;
	int		b;
	size_t	total;
}	t_cost;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_flag
{
	t_strategy	strategy;
	int			bench;
}	t_flag;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_ops;

//Simple sort
void	ft_simple_sort(t_stack *a, t_stack *b, t_ops *ops);
void	ft_sort3(t_stack *a, t_ops *ops);
t_cost	ft_find_cheapest(t_stack *a, t_stack *b);

//Algoritm adaptive
void	adaptive(t_stack *a, t_stack *b, t_ops *op, double disorder_index);

// Main
int		main(int argc, char *argv[]);

//complex sort
void	ft_complex_sort(t_stack *a, t_stack *b, t_ops *ops);

//Operators
void	pa(t_stack *a, t_stack *b, t_ops *ops);
void	pb(t_stack *a, t_stack *b, t_ops *ops);
void	sa(t_stack *a, t_ops *ops);
void	sb(t_stack *b, t_ops *ops);
void	ss(t_stack *a, t_stack *b, t_ops *ops);
void	ra(t_stack *a, t_ops *ops);
void	rb(t_stack *b, t_ops *ops);
void	rr(t_stack *a, t_stack *b, t_ops *ops);
void	rra(t_stack *a, t_ops *ops);
void	rrb(t_stack *b, t_ops *ops);
void	rrr(t_stack *a, t_stack *b, t_ops *ops);

//Stack manipulation functions
void	ft_stack_add_front(t_stack *stack, t_node *new);
void	ft_stack_add_back(t_stack *stack, t_node *new);
t_node	*ft_detach_stack_head(t_stack *stack);

// Utils
double	compute_disorder(t_stack *stack);
void	dynamic_chunk(t_stack *a, t_stack *b, t_ops *op);
int		parse_input(int argc, char **argv, t_stack *stack, int index);
void	free_stack(t_stack *stack);
void	write_error(void);
void	ft_assign_index(t_stack *a);

#endif
