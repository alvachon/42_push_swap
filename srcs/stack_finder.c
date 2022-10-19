/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:55:11 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 16:30:56 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_biggest(t_node *node)
{
	t_node	*most_big;
	t_node	*head;

	most_big = node;
	head = node;
	while (node->link_next != head)
	{
		if (node->data > most_big->data)
			most_big = node;
		node = node->link_next;
	}
	if (node->data > most_big->data)
		most_big = node;
	node = most_big;
	return (node);
}

t_node	*find_smallest(t_node *node)
{
	t_node	*most_small;
	t_node	*head;

	most_small = node;
	head = node;
	while (node->link_next != head)
	{
		if (node->data < most_small->data)
			most_small = node;
		node = node->link_next;
	}
	if (node->data < most_small->data)
		most_small = node;
	node = most_small;
	return (node);
}