/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:38:51 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 16:44:17 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void adaptive(t_stack *a, t_stack *b, t_ops *op, double disorder_index)
{
	if (disorder_index < 0.2)
		ft_simple_sort(&a, &b, &op);
	if (disorder_index >= 0.2 && disorder_index < 0.5)
		dynamic_chunk(&a, &b, &op);
	if (disorder_index >= 0.5)
		ft_complex_sort(&a, &b, &op);
}
