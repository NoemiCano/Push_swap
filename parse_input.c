/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:44:09 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/24 13:24:37 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// Mira si el token empieza por + o - y avanza la posición de lectura.
static int	get_sign(const char *token, int *i)
{
    int	sign;

    sign = 1;
    if (token[*i] == '+' || token[*i] == '-')
    {
        if (token[*i] == '-')
            sign = -1;
        (*i)++;
    }
    return (sign);
}

// Valida el token y lo convierte. Comprueba que haya dígitos, que no haya caracteres sobrantes ("12x") y que el valor quepa en un int.
static int	token_to_int(const char *token, int *result)
{
    int			i;
    int			sign;
    int			digit;
    long long	value;
    long long	limit;

    i = 0;
    value = 0;
    sign = get_sign(token, &i);
    if (!token[i])
        return (0);
    limit = INT_MAX;
    if (sign < 0)
        limit = -(long long)INT_MIN;
    while (token[i])
    {
        if (!ft_isdigit((unsigned char)token[i]))
            return (0);
        digit = token[i] - '0';
        if (value > (limit - digit) / 10)
            return (0);
        value = value * 10 + digit;
        i++;
    }
    if (sign < 0 && value == -(long long)INT_MIN)
        *result = INT_MIN;
    else
        *result = (int)(value * sign);
    return (1);
}

// Recorre los nodos ya añadidos y comprueba si el valor está repetido.
static int	has_duplicate(t_stack *stack, int value)
{
    t_node	*current;
    int		i;

    current = stack->head;
    i = 0;
    while (i < stack->size)
    {
        if (current->value == value)
            return (1);
        current = current->next;
        i++;
    }
    return (0);
}

// Coordina las operaciones para un token: convertirlo, rechazar duplicados, reservar el nodo y añadirlo al stack.
static int	add_token(t_stack *stack, char *token)
{
    t_node	*node;
    int		value;

    if (!token_to_int(token, &value) || has_duplicate(stack, value))
        return (0);
    node = ft_calloc(1, sizeof(*node));
    if (!node)
        return (0);
    node->value = value;
    ft_stack_add_back(stack, node);
    return (1);
}

// Recorre los argumentos recibidos y usa ft_split en cada uno. Así acepta tanto ./push_swap 3 2 1 como ./push_swap "3 2 1". Hay que liberar memoria despues del ft_split
int	parse_input(int argc, char **argv, t_stack *stack)
{
    char	**words;
    int		i;
    int		j;
    int		valid;

    i = 1;
    while (i < argc)
    {
        words = ft_split(argv[i], ' ');
        if (!words)
            return (0);
        valid = 1;
        j = 0;
        while (words[j])
        {
            valid = valid && add_token(stack, words[j]);
            free(words[j]);
            j++;
        }
        free(words);
        if (!valid)
            return (0);
        i++;
    }
    return (stack->size > 0);
}
