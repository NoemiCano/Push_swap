/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/20 17:50:03 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // Es para incluir NULL y size_t
	
typedef struct s_list	//lista para cada valor
{
	int				value;	//valor de la posicion del stack
	struct s_list	*next;	//proxima posicion del stack
	struct s_list	*prev;	//posicion previa del stack
}	t_list;

typedef struct s_stack	//lista para cada stack
{
	t_list	*head;		//apunta al primer elemento del stack
	int		size;		//tamaño del stack
}	t_stack;

//Stack manipulation functions
void	ft_stack_add_front(t_stack *stack, t_list *new);
void	ft_stack_add_back(t_stack *stack, t_list *new);
t_list	*ft_detach_stack_head(t_stack *stack); 

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


void	insertion(int arr, int size);

#endif
