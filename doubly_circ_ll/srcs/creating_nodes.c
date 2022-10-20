/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:20:32 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 14:05:49 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doubly_circ_ll.h"

t_node	*ft_add_to_empty(t_node *head, int data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp->link_prev = temp;
	temp->data = data;
	temp->index = -1;
	temp->link_next = temp;
	head = temp;
	return (head);
}

t_node	*ft_add_to_one(t_node *head, int data)
{
	t_node	*new_top;
	t_node	*new_queue;

	new_top = head;
	new_queue = malloc(sizeof(t_node));
	if (new_queue == NULL)
		return (NULL);
	new_queue->link_prev = new_top;
	new_top->link_next = new_queue;
	new_top->link_prev = new_queue;
	new_queue->data = data;
	new_queue->index = -1;
	new_queue->link_next = new_top;
	head = new_top;
	return (head);
}

t_node	*relink_circular(t_node **new, t_node **old, t_node **top, t_node **h)
{
	(*new)->link_prev = *old;
	(*old)->link_next = *new;
	(*new)->link_next = *top;
	(*top)->link_prev = *new;
	*h = *top;
	return (*h);
}

t_node	*ft_add_at_end(t_node *head, t_node *queue, int data)
{
	t_node	*new_queue;
	t_node	*old_queue;
	t_node	*top;

	top = head;
	old_queue = queue;
	new_queue = malloc(sizeof(t_node));
	if (new_queue == NULL)
		return (NULL);
	new_queue->data = data;
	new_queue->index = -1;
	if (top->link_prev != top)
		return (relink_circular(&new_queue, &old_queue, &top, &head));
	else
	{
		old_queue->link_next = top;
		head = top;
		return (head);
	}
}
