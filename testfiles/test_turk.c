#include "ft_push_swap.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void	ft_init_stacks(t_stack *a, t_stack *b)
{
	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
}

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
	t_node	*current;
	int		i;

	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (0);
		current = current->next;
		i++;
	}
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

static int	ft_is_sorted(t_stack *a, int expected_size)
{
	t_node	*node;
	int		i;

	if (!a->head || a->size != expected_size)
		return (0);
	node = a->head;
	i = 0;
	while (i + 1 < a->size)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	size_t	operations;
	int		value;
	int		i;
	int		sorted;

	if (argc < 2)
		return (fprintf(stderr, "Usage: ./turk_test n1 n2 ...\n"), 1);
	ft_init_stacks(&a, &b);
	i = 1;
	while (i < argc)
	{
		if (!ft_parse_int(argv[i], &value) || !ft_append_node(&a, value))
		{
			fprintf(stderr, "Invalid input, duplicate values, or allocation failure\n");
			ft_free_stack(&a);
			return (1);
		}
		i++;
	}
	operations = ft_simple_sort(&a, &b);
	sorted = (b.size == 0 && ft_is_sorted(&a, argc - 1));
	fprintf(stderr, "Operations: %zu\n", operations);
	if (sorted)
		fprintf(stderr, "Result: OK\n");
	else
		fprintf(stderr, "Result: KO\n");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (!sorted);
}
