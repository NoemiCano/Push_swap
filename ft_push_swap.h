/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 17:38:51 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // Es para incluir NULL y size_t
#include <limits.h> // Es para los INT_MIN y INT_MAX - comprobar que se pueden usar
#include <stdio.h>
	
typedef struct s_node	//nodo para cada valor
{
	int				value;	//valor de la posicion del stack
	int				index;	//Para asignales posiciones de ordenación del stack	
	struct s_node	*next;	//proxima posicion del stack
	struct s_node	*prev;	//posicion previa del stack
}	t_node;

typedef struct s_stack //lista para cada stack
{
	t_node	*head;		//apunta al primer elemento del stack
	int		size;		//tamaño del stack
}	t_stack;
typedef struct s_cost //para calcular el coste en operaciones para mover nodos entre stacks (algoritmo simple)
{
	int		a;
	int		b;
	size_t	total;
}	t_cost;

typedef enum	e_strategy
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


//Stack manipulation functions
void	ft_stack_add_front(t_stack *stack, t_node *new);
void	ft_stack_add_back(t_stack *stack, t_node *new);
t_node	*ft_detach_stack_head(t_stack *stack);

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

//Simple sort
void	ft_simple_sort(t_stack *a, t_stack *b);
void	ft_sort3(t_stack *a);
t_cost	ft_find_cheapest(t_stack *a, t_stack *b);

//complex sort
void	ft_complex_sort(t_stack *a, t_stack *b);

//TBD
void	insertion(int arr, int size);
void	ft_assign_index(t_stack *a);

//Funciones de ayuda !!BORRAR ANTES DE ENTREGA!!
void	print_stacks(t_stack *a, t_stack *b);


// Funciones
int		main(int argc, char *argv[]);
double	compute_disorder(t_stack *stack);
void	dynamic_chunk(t_stack *a, t_stack *b, t_ops *op);
int		parse_input(int argc, char **argv, t_stack *stack, int index);
void	free_stack(t_stack *stack);
void	write_error(void);
void	adaptive(t_stack *a, t_stack *b, t_ops *op, double disorder_index);

#endif
