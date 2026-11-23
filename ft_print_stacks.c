/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 20:15:40 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/22 16:11:25 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static void print_stack(t_stack *a, char name)
{
	t_node	*tmp;

	printf("values: %c: {", name);
	tmp = a->head;
	while (a->head->prev != tmp)
	{
		printf("%d, ", tmp->value);
		tmp = tmp->next;
	}
	printf("%d} (%d)\n", a->head->prev->value, a->size);

}


void	print_stacks(t_stack *a, t_stack *b)
{
	if (a && a->head)
		print_stack(a, 'A');
	if (b && b->head)
		print_stack(b, 'B');
}
