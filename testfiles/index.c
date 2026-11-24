#include "ft_push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_node	n1 = {42, -1, NULL, NULL};
	t_node	n2 = {-7, -1, NULL, NULL};
	t_node	n3 = {100, -1, NULL, NULL};
	t_node	n4 = {15, -1, NULL, NULL};

	a.head = NULL;
	a.size = 0;

	ft_stack_add_front(&a, &n1);
	ft_assign_index(&a);
	printf("Single node:\n");
	printf("Value: %d | Index: %d\n\n", n1.value, n1.index);

	a.head = NULL;
	a.size = 0;
	ft_stack_add_front(&a, &n2);
	ft_stack_add_back(&a, &n3);
	ft_assign_index(&a);
	printf("Two nodes:\n");
	printf("Value: %d | Index: %d\n", n2.value, n2.index);
	printf("Value: %d | Index: %d\n\n", n3.value, n3.index);

	a.head = NULL;
	a.size = 0;
	ft_stack_add_front(&a, &n1);
	ft_stack_add_back(&a, &n2);
	ft_stack_add_back(&a, &n3);
	ft_stack_add_back(&a, &n4);
	ft_assign_index(&a);
	printf("Four nodes:\n");
	printf("Value: %d | Index: %d\n", n1.value, n1.index);
	printf("Value: %d | Index: %d\n", n2.value, n2.index);
	printf("Value: %d | Index: %d\n", n3.value, n3.index);
	printf("Value: %d | Index: %d\n", n4.value, n4.index);
	return (0);
}
