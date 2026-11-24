t_node	old_find_target(t_stack *a, t_stack *b, t_node *node_b, t_cost *new)
{
	t_node	*node_a;
	t_node	target;
	int		i;

	i = 0;
	node_a = a->head;
	target = (t_node){0, a->size + b->size, NULL, NULL};
	while (1)
	{
		if (node_a->index > node_b->index && node_a->index < target.index)		//parsea y encuentra el nuevo index mas bajo que este
			(target = (t_node){i, node_a->index, NULL, NULL}, new.a = i);	//por encima del nodo analizado de b
		node_a = node_a->next;
		if (node_a == a->head)
			break ;
		i++;
	}
	if (target.index == a->size + b->size) //en caso de no encontrar ninguno valido (node_b es mayor que todo el stack a)
	{
		i = 0;
		node_a = a->head;
		while (1)
		{
			if (node_a->index < target.index) //busca el index mas pequeño del stack a
				(target = (t_node){i, node_a->index, NULL, NULL}, new.a = i);
			node_a = node_a->next;
			if (node_a == a->head)
				break ;
			i++;
		}
	}
	return (target);
}
