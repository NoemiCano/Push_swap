#include "ft_push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static t_stack	*create_stack(int *values)
{
	t_stack	*a;
	t_node	*n0;
	t_node	*n1;
	t_node	*n2;

	a = malloc(sizeof(t_stack));
	n0 = malloc(sizeof(t_node));
	n1 = malloc(sizeof(t_node));
	n2 = malloc(sizeof(t_node));
	n0->index = values[0];
	n1->index = values[1];
	n2->index = values[2];
	n0->next = n1;
	n1->next = n2;
	n2->next = n0;
	n0->prev = n2;
	n1->prev = n0;
	n2->prev = n1;
	a->head = n0;
	a->size = 3;
	return (a);
}

static int	is_sorted(t_stack *a)
{
	return (a->head->index < a->head->next->index
		&& a->head->next->index < a->head->prev->index);
}

static void	print_stack(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	printf("[");
	while (tmp != a->head->prev)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("%d]\n", tmp->index);
}

int	main(void)
{
	int		tests[6][3] = {
		{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
		{1, 2, 0}, {2, 0, 1}, {2, 1, 0}
	};
	size_t	expected[6] = {0, 2, 1, 1, 1, 2};
	size_t	ops;
	t_stack	*a;
	int		i;

	i = -1;
	while (++i < 6)
	{
		a = create_stack(tests[i]);
		printf("Test %d: ", i + 1);
		print_stack(a);
		ops = ft_sort3(a);
		printf("Result: ");
		print_stack(a);
		printf("Operations: %zu | Expected: %zu | Sorted: %s | Count: %s\n",
			ops, expected[i], is_sorted(a) ? "YES" : "NO",
			ops == expected[i] ? "PASS" : "FAIL");
		free(a->head->next->next);
		free(a->head->next);
		free(a->head);
		free(a);
	}
	return (0);
}
