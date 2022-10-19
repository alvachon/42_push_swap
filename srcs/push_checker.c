/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:46:48 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 15:47:37 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_empty(t_node ***head, t_node ***empty)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (temp == NULL)
       	return ;
	temp->link_prev = temp;
	temp->data = (**head)->data;
	temp->index = (**head)->index;
	temp->link_next = temp;
	**empty = temp;
}

void	push_to_one(t_node ***head, t_node ***to_one)
{
	t_node	*new_top;
	t_node	*new_queue;

	new_top = malloc(sizeof(t_node));
	if (new_top == NULL)
       	return ;
	new_queue = **to_one;
	new_queue->link_prev = new_top;
	new_queue->link_next = new_top;
	new_top->link_next = new_queue;
	new_top->data = (**head)->data;
	new_top->index = (**head)->index;
	new_top->link_prev = new_queue;
	**to_one = new_top;
}

void	push_at_head(t_node ***head, t_node ***to_head)
{
	t_node	*new_top;
	t_node	*old_top;
	t_node	*queue;

	queue = (**to_head)->link_prev;
	old_top = **to_head;
	new_top = malloc(sizeof(t_node));
	if (new_top == NULL)
       	return ;
	new_top->link_prev = queue;
	new_top->data = (**head)->data;
	new_top->index = (**head)->index;
	new_top->link_next = old_top;
	old_top->link_prev = new_top;
	queue->link_next = new_top;
	**to_head = new_top;
}

void	pop_head(t_node **node)
{
	t_node	*temp;
	t_node	*tail;

	if (*node != NULL)
	{
		temp = *node;
		tail = (*node)->link_prev;
		if (*node == tail)
		{
			*node = NULL;
			return ;
		}
		*node = (*node)->link_next;
		(*node)->link_prev = tail;
		tail->link_next = *node;
	}
}