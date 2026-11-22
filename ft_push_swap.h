/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 17:04:28 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // Es para incluir NULL y size_t
	
typedef struct s_node	//nodo para cada valor
{
	int				value;	//valor de la posicion del stack
	int				index;	//Para asignarles posiciones de ordenación del stack
	struct s_node	*next;	//proxima posicion del stack
	struct s_node	*prev;	//posicion previa del stack
}	t_node;

typedef struct s_stack	//lista para cada stack
{
	t_node	*head;		//apunta al primer elemento del stack
	int		size;		//tamaño del stack
}	t_stack;

//Stack manipulation functions
void	ft_stack_add_front(t_stack *stack, t_node *new);
void	ft_stack_add_back(t_stack *stack, t_node *new);
t_node	*ft_detach_stack_head(t_stack *stack); 

//Operators
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//TBD
void	insertion(int arr, int size);
void	ft_assign_index(t_stack *a);

//Funciones de ayuda !!BORRAR ANTES DE ENTREGA!!
void	print_stacks(t_stack *a, t_stack *b);

#endif
