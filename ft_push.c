/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:35:47 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 17:12:49 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (push a): Toma el primer elemento del stack b y lo coloca el primero en el stack a. No hace nada si b está vacío.
void	pa(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || !b->head)
		return (0);
	ft_putstr_fd("pa\n", 1);
	ft_stack_add_front(a, ft_detach_stack_head(b));
	*pa++;
	*total++;
}

// (push b): Toma el primer elemento del stack a y lo coloca el primero en el stack b. No hace nada si a está vacío.
void	pb(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || !a->head)
		return (0);
	ft_putstr_fd("pb\n", 1);
	ft_stack_add_front(b, ft_detach_stack_head(a));
	*pb++;
	*total++;
}
