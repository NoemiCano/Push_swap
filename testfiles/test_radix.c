#include "ft_push_swap.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_parse_int(char *arg, int *value)
{
	char	*end;
	long	number;

	errno = 0;
	number = strtol(arg, &end, 10);
	if (arg == end || *end || errno == ERANGE
		|| number < INT_MIN || number > INT_MAX)
		return (0);
	*value = (int)number;
	return (1);
}

static int	ft_append_node(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*tail;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	node->index = -1;
	if (!stack->head)
	{
		node->next = node;
		node->prev = node;
		stack->head = node;
	}
	else
	{
		tail = stack->head->prev;
		node->next = stack->head;
		node->prev = tail;
		tail->next = node;
		stack->head->prev = node;
	}
	stack->size++;
	return (1);
}

static int	ft_assign_indexes(t_stack *stack)
{
	t_node	*node;
	t_node	*current;
	int		i;
	int		j;
	int		rank;

	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		rank = 0;
		current = stack->head;
		j = 0;
		while (j < stack->size)
		{
			if (current != node && current->value == node->value)
				return (0);
			if (current->value < node->value)
				rank++;
			current = current->next;
			j++;
		}
		node->index = rank;
		node = node->next;
		i++;
	}
	return (1);
}

static int	ft_build_stack(t_stack *a, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_parse_int(argv[i], &value) || !ft_append_node(a, value))
			return (0);
		i++;
	}
	return (ft_assign_indexes(a));
}

static void	ft_print_stack(char *name, t_stack *stack)
{
	t_node	*node;
	int		i;

	fprintf(stderr, "%s:", name);
	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		fprintf(stderr, " %d[%d]", node->value, node->index);
		node = node->next;
		i++;
	}
	fprintf(stderr, "\n");
}

static int	ft_is_sorted(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	i = 0;
	while (i + 1 < stack->size)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

static void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;
	int		i;

	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		next = node->next;
		free(node);
		node = next;
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}

static void	ft_init_stacks(t_stack *a, t_stack *b)
{
	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
}

static int	ft_report_result(t_stack *a, t_stack *b, int expected, size_t moves)
{
	int	sorted;

	sorted = (a->size == expected && b->size == 0 && ft_is_sorted(a));
	fprintf(stderr, "\nOperations reported: %zu\n", moves);
	ft_print_stack("A", a);
	ft_print_stack("B", b);
	if (sorted)
		fprintf(stderr, "Result: OK\n");
	else
		fprintf(stderr, "Result: KO\n");
	return (sorted);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	size_t	movements;
	int		sorted;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: ./test_radix n1 n2 ...\n");
		return (1);
	}
	ft_init_stacks(&a, &b);
	if (!ft_build_stack(&a, argc, argv))
	{
		fprintf(stderr, "Invalid input, duplicate values, or allocation failure\n");
		ft_free_stack(&a);
		return (1);
	}
	movements = ft_complex_sort(&a, &b);
	sorted = ft_report_result(&a, &b, argc - 1, movements);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (!sorted);
}
