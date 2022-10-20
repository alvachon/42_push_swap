/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:39:59 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 12:28:23 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_select(t_get stack, t_all *info)
{
	if (stack == L_A)
		return (info->l_a);
	else if (stack == L_B)
		return (info->l_b);
	return (NULL);
}

void	move_swap(t_get stack, t_all *info)
{
	if (stack == L_A)
	{
		if (!info->l_a || !info->l_a->link_next)
			return ;
		swap(info->l_a, info->l_a->link_next);
		write_op("sa\n");
	}
	else if (stack == L_B)
	{
		if (!info->l_b || !info->l_b->link_next)
			return ;
		swap(info->l_b, info->l_b->link_next);
		write_op("sb\n");
	}
	else if (stack == BOTH)
	{
		if (!info->l_a || !info->l_a->link_next)
			return ;
		if (!info->l_b || !info->l_b->link_next)
			return ;
		swap(info->l_a, info->l_a->link_next);
		swap(info->l_b, info->l_b->link_next);
		write_op("ss\n");
	}
}

void	move_reverse_rotate(t_get stack, t_all *info)
{
	if (stack == L_A)
	{
		if (!info->l_a || !info->l_a->link_next)
			return ;
		reverse_rotate(&info->l_a);
		write_op("rra\n");
	}
	else if (stack == L_B)
	{
		if (!info->l_b || !info->l_b->link_next)
			return ;
		reverse_rotate(&info->l_b);
		write_op("rrb\n");
	}
}

void	move_rotate(t_get stack, t_all *info)
{
	if (stack == L_A)
	{
		if (!info->l_a || !info->l_a->link_next)
			return ;
		rotate(&info->l_a);
		write_op("ra\n");
	}
	else if (stack == L_B)
	{
		if (!info->l_b || !info->l_b->link_next)
			return ;
		rotate(&info->l_b);
		write_op("rb\n");
	}
}

void	move_push(t_get stack, t_all *info)
{
	if (stack == L_A)
	{
		if (!info->l_a)
			return ;
		push_checker(&info->l_a, &info->l_b);
		write_op("pb\n");
	}
	else if (stack == L_B)
	{
		if (!info->l_b)
			return ;
		push_checker(&info->l_b, &info->l_a);
		write_op("pa\n");
	}
}
