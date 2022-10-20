/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:08:34 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 13:50:10 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	repeat_op(void (*op)(t_get, t_all *), int i, t_get stack, t_all *info)
{
	while (i)
	{
		op(stack, info);
		i--;
	}
}

void	do_less_moves_to_tail(int pos, int len, t_get stack, t_all *info)
{
	if (pos < len / 2)
		repeat_op(move_rotate, pos + 1, stack, info);
	else
		repeat_op(move_reverse_rotate, len - pos - 1, stack, info);
}

void	put_at_tail(t_node *target, t_get stack, t_all *info)
{
	t_node	*head;
	t_node	*node;
	int		pos;
	int		len;

	head = ft_select(stack, info);
	len = total_items(head);
	node = head;
	pos = 0;
	while (node->link_next != head)
	{
		if (target == node)
			do_less_moves_to_tail(pos, len, stack, info);
		pos++;
		node = node->link_next;
	}
	if (target == node)
		do_less_moves_to_tail(pos, len, stack, info);
}

void	do_less_moves_to_head(int pos, int len, t_get stack, t_all *info)
{
	if (pos < len / 2)
		repeat_op(move_rotate, pos, stack, info);
	else
		repeat_op(move_reverse_rotate, len - pos, stack, info);
}

void	put_at_head(t_node *target, t_get stack, t_all *info)
{
	t_node	*head;
	t_node	*node;
	int		pos;
	int		len;

	head = ft_select(stack, info);
	len = total_items(head);
	node = head;
	pos = 0;
	while (node->link_next != head)
	{
		if (target == node)
			do_less_moves_to_head(pos, len, stack, info);
		pos++;
		node = node->link_next;
	}
	if (target == node)
		do_less_moves_to_head(pos, len, stack, info);
}
