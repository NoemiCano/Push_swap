/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:57:46 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 10:32:03 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // Es para incluir NULL y size_t

typedef struct s_list	//lista para cada valor
{
	int				value;	//valor de la posicion del stack
	struct s_list	*next;	//proxima posicion del stack
	struct s_list	*prev;	//posicion previa del stack
}	t_list;

typedef struct s_stack	//lista para cada stack
{
	t_list	*head;		//apunta al primer elemento del stack
	int		size;		//tamaño del stack
}	t_stack;


void	insertion(int arr, int size);

#endif
