/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:01:54 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/22 18:42:03 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Calcular cuantos valores son mas pequeños
static int count_smaller(t_node *start, int target_value)
{
	t_node	*cmp;
	int		smaller;

	if (!start)
		return (0);
	smaller = 0;
	cmp = start;
	while (1)
	{
		if (cmp->value < target_value)
			smaller++;
		cmp = cmp->next;
		if (!cmp || cmp == start)
			break ;
	}
	return (smaller);
}

// Asignar un índice al stack
void	ft_assign_index(t_stack *a)
{
	t_node	*current;

	if (!a || !a->head || a->size <= 0)
		return ;
	current = a->head;
	while (a)
	{
		current->index = count_smaller(a->head, current->value);
		current = current->next;
		if (!current || current == a->head)
			break ;
	}
}
