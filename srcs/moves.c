/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:44:12 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/26 12:12:17 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node	*head, t_node *next)
{
	int	temp;

	temp = head->data;
	head->data = next->data;
	next->data = temp;
}

void	rotate(t_node **node)
{
	*node = (*node)->link_next;
}

void	reverse_rotate(t_node **node)
{
	*node = (*node)->link_prev;
}

void	push_checker(t_node **from, t_node **to)
{
	if (total_items(*to) == 0)
		push_to_empty(&*from, &*to);
	else
		push_at_head(&*from, &*to);
}
