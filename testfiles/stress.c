
#include "ft_push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static int	parse_value(char *arg, int *value)
{
	char	*end;
	long	num;

	errno = 0;
	num = strtol(arg, &end, 10);
	if (errno || *arg == '\0' || *end
		|| num < INT_MIN || num > INT_MAX)
		return (0);
	*value = (int)num;
	return (1);
}

static int	is_sorted(t_stack *a, t_stack *b, int expected)
{
	t_node	*node;
	int		i;

	if (a->size != expected || b->size != 0 || !a->head)
		return (0);
	node = a->head;
	i = 0;
	while (i < expected)
	{
		if (node->index != i)
			return (0);
		node = node->next;
		i++;
	}
	return (node == a->head);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*nodes;
	size_t	ops;
	int		n;
	int		i;
	int		sorted;

	n = argc - 1;
	if (n < 3)
		return (fprintf(stderr, "Minimum: 3 elements\n"), 1);
	nodes = malloc((size_t)n * sizeof(*nodes));
	if (!nodes)
		return (perror("malloc"), 1);
	i = 0;
	while (i < n)
	{
		if (!parse_value(argv[i + 1], &nodes[i].value))
			return (free(nodes), fprintf(stderr, "Invalid input\n"), 1);
		nodes[i].index = 0;
		nodes[i].next = &nodes[(i + 1) % n];
		nodes[i].prev = &nodes[(i + n - 1) % n];
		i++;
	}
	a = (t_stack){nodes, n};
	b = (t_stack){NULL, 0};

	printf("\nBefore sorting:\n");
	print_stacks(&a, &b);
	fflush(stdout);

	ops = ft_simple_sort(&a, &b);

	printf("\nAfter sorting:\n");
	print_stacks(&a, &b);

	sorted = is_sorted(&a, &b, n);
	fprintf(stderr, "Result: %s\n", sorted ? "OK" : "KO");
	fprintf(stderr, "Operations: %zu\n", ops);
	free(nodes);
	return (!sorted);
}

