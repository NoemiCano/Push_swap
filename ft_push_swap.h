/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/27 18:47:03 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // Es para incluir NULL y size_t

typedef struct s_node //nodo para cada valor
{
	int				value;	//valor de la posicion del stack
	int				index;	//Para asignarles posiciones de ordenación del stack
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

//Stack manipulation functions
void	ft_stack_add_front(t_stack *stack, t_node *new);
void	ft_stack_add_back(t_stack *stack, t_node *new);
t_node	*ft_detach_stack_head(t_stack *stack);

//Operators
size_t	pa(t_stack *a, t_stack *b);
size_t	pb(t_stack *a, t_stack *b);
size_t	sa(t_stack *a);
size_t	sb(t_stack *b);
size_t	ss(t_stack *a, t_stack *b);
size_t	ra(t_stack *a);
size_t	rb(t_stack *b);
size_t	rr(t_stack *a, t_stack *b);
size_t	rra(t_stack *a);
size_t	rrb(t_stack *b);
size_t	rrr(t_stack *a, t_stack *b);

//Simple sort
size_t	ft_simple_sort(t_stack *a, t_stack *b);
size_t	ft_sort3(t_stack *a);
t_cost	ft_find_cheapest(t_stack *a, t_stack *b);

//complex sort
size_t	ft_complex_sort(t_stack *a, t_stack *b);

//TBD
void	insertion(int arr, int size);
void	ft_assign_index(t_stack *a);

//Funciones de ayuda !!BORRAR ANTES DE ENTREGA!!
void	print_stacks(t_stack *a, t_stack *b);

#endif
