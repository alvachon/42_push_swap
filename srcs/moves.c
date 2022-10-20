/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:44:12 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 12:47:07 by alvachon         ###   ########.fr       */
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
	if (*to == NULL)
		push_to_empty(&from, &to);
	else if ((*to)->link_next == *to)
		push_to_one(&from, &to);
	else
		push_at_head(&from, &to);
	pop_head(&*from);
}
