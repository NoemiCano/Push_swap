#include "ft_push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_node	nodes[3];
	size_t	ops;

	nodes[0] = (t_node){3, 0, &nodes[1], &nodes[2]};
	nodes[1] = (t_node){1, 0, &nodes[2], &nodes[0]};
	nodes[2] = (t_node){2, 0, &nodes[0], &nodes[1]};
	a = (t_stack){&nodes[0], 3};
	b = (t_stack){NULL, 0};
	print_stacks(&a, &b);
	ops = ft_simple_sort(&a, &b);
	print_stacks(&a, &b);
	printf("Operations: %zu\n", ops);
	return (0);
}
