#include "ft_push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	init_stack(t_stack *stack, int *values, int size)
{
	t_node	*nodes[10];
	int		i;

	stack->size = size;
	stack->head = NULL;
	if (!size)
		return ;
	i = 0;
	while (i < size)
	{
		nodes[i] = malloc(sizeof(t_node));
		nodes[i]->value = values[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		nodes[i]->next = nodes[(i + 1) % size];
		nodes[i]->prev = nodes[(i + size - 1) % size];
		i++;
	}
	stack->head = nodes[0];
}

int	main(void)
{
	t_stack	a;
	t_stack	b;
	int		va[] = {3, 5, 6, 7, 9};
	int		vb[] = {10, 20, 30};

	printf("=== BOTH EMPTY ===\n");
	init_stack(&a, NULL, 0);
	init_stack(&b, NULL, 0);
	print_stacks(&a, &b);

	printf("\n=== A: 1 NODE, B: EMPTY ===\n");
	init_stack(&a, va, 1);
	init_stack(&b, NULL, 0);
	print_stacks(&a, &b);

	printf("\n=== A: 2 NODES, B: 1 NODE ===\n");
	init_stack(&a, va, 2);
	init_stack(&b, vb, 1);
	print_stacks(&a, &b);

	printf("\n=== A: 3 NODES, B: 2 NODES ===\n");
	init_stack(&a, va, 3);
	init_stack(&b, vb, 2);
	print_stacks(&a, &b);

	printf("\n=== A: 5 NODES, B: 3 NODES ===\n");
	init_stack(&a, va, 5);
	init_stack(&b, vb, 3);
	print_stacks(&a, &b);

	printf("\n=== A: EMPTY, B: 3 NODES ===\n");
	init_stack(&a, NULL, 0);
	init_stack(&b, vb, 3);
	print_stacks(&a, &b);
	return (0);
}
