/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:35:47 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 17:14:23 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || !b->head)
		return (0);
	ft_putstr_fd("pa\n", 1);
	ft_stack_add_front(a, ft_detach_stack_head(b));
	*pa++;
	*total++;
}

void	pb(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || !a->head)
		return (0);
	ft_putstr_fd("pb\n", 1);
	ft_stack_add_front(b, ft_detach_stack_head(a));
	*pb++;
	*total++;
}
