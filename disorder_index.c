/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:52:52 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/22 18:42:37 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Calcula el índice de deshorden entre 0 y 1.
double compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	long	mistakes;
	int		i;
	int		j;

	i = 0;
	mistakes = 0;
	current = stack->head;
	if (!stack || stack->size <= 1 || !stack->head)
		return (0.0);
	while (i < stack->size - 1)
	{
		runner = current->next;
		j = i + 1;
		while (j++ < stack->size)
		{
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
		i++;
	}
	return ((double)mistakes / (((double)stack->size * (stack->size - 1)) / 2.0));
}
