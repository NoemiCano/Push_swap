/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 20:15:40 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 20:32:20 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->head && b->head)
	{
		printf("Values: A: {");
		tmp = a->head;
		while (a->head->prev != tmp)
		{
			printf("%d, ", tmp->value);
			tmp = tmp->next;
		}
		printf("%d}\n", a->head->prev->value);
		printf("Values: B: {");
		tmp = b->head;
		while (b->head->prev != tmp)
		{
			printf("%d, ", tmp->value);
			tmp = tmp->next;
		}
		printf("%d}\n", b->head->prev->value);
	}
	else if (a->head && !b->head)
	{
		printf("Values: A: {");
		tmp = a->head;
		while (a->head->prev != tmp)
		{
			printf("%d, ", tmp->value);
			tmp = tmp->next;
		}
		printf("%d}\n", a->head->prev->value);
	}
	else if (b->head && !a->head)
	{
		printf("Values: B: {");
		tmp = b->head;
		while (b->head->prev != tmp)
		{
			printf("%d, ", tmp->value);
			tmp = tmp->next;
		}
		printf("%d}\n", b->head->prev->value);
	}
}
