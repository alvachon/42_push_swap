/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:46:48 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/25 17:14:34 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_empty(t_node **head_la, t_node **head_lb)
{
	t_node	*temp;
	t_node	*queue;

	temp = *head_la;
	queue = (*head_la)->link_prev;
	*head_lb = temp;
	*head_la = (*head_la)->link_next;
	(*head_lb)->link_next = temp;
	(*head_lb)->link_prev = temp;
	(*head_la)->link_prev = queue;
	queue->link_next = *head_la;
}

void	push_at_head(t_node **head_la, t_node **head_lb)
{
	t_node	*temp;
	t_node	*queue_la;
	t_node	*queue_lb;

	temp = *head_la;
	queue_la = (*head_la)->link_prev;
	queue_lb = (*head_lb)->link_prev;
	if (temp->data == queue_la->data)
	{
		temp->link_next = *head_lb;
		(*head_lb)->link_prev = temp;
		*head_lb = (*head_lb)->link_prev;
		queue_lb->link_next = *head_lb;
		(*head_lb)->link_prev = queue_lb;
		*head_la = NULL;
		return ;
	}
	*head_la = (*head_la)->link_next;
	(*head_la)->link_prev = queue_la;
	queue_la->link_next = *head_la;
	(*head_lb)->link_prev = temp;
	temp->link_next = *head_lb;
	*head_lb = (*head_lb)->link_prev;
	queue_lb->link_next = *head_lb;
	(*head_lb)->link_prev = queue_lb;
}
