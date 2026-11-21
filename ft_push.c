/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:35:47 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 13:18:43 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (push a): Toma el primer elemento del stack b y lo coloca el primero en el stack a. No hace nada si b está vacío.
void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->head)
		return ;
	ft_putstr_fd("pa\n", 1);
	ft_stack_add_front(a, ft_detach_stack_head(b));
}

// (push b): Toma el primer elemento del stack a y lo coloca el primero en el stack b. No hace nada si a está vacío.
void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->head)
		return ;
	ft_putstr_fd("pb\n", 1);
	ft_stack_add_front(b, ft_detach_stack_head(a));
}
