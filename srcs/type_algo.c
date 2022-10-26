/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:36:49 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/26 12:40:24 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	in_place_two(t_get stack, t_all *info)
{
	t_node	*node;

	node = ft_select(stack, info);
	if (node->data > node->link_next->data)
		move_swap(stack, info);
}

void	in_place_three(t_get stack, t_all *info)
{
	t_node	*list;

	list = ft_select(stack, info);
	put_at_tail(find_biggest(list), stack, info);
	in_place_two(stack, info);
}

void	check_reverse(t_all *info)
{
	t_node	*a;
	t_node	*b;

	a = info->l_a;
	b = info->l_b;
	if (a < a->link_next && a < a->link_prev && b > b->link_next
		&& b > b->link_prev)
	{
		move_reverse_rotate(BOTH, &info);
		move_swap(BOTH, &info);
	}
	else if (a < a->link_next && a < a->link_prev)
	{
		move_reverse_rotate(L_A, &info);
		move_swap(L_A, &info);
	}
	else if (b > b->link_next && b > b->link_prev)
	{
		move_reverse_rotate(L_B, &info);
		move_swap(L_B, &info);
	}

}

void	conditional_move(t_all *info)
{
	t_node	*a;
	t_node	*b;

	a = info->l_a;
	b = info->l_b;
	if (a > a->link_next && a < a->link_prev && b < b->link_next
		&& b > b->link_prev)
		move_swap(BOTH, &info);
	else if (a > a->link_next && a < a->link_prev)
		move_swap(L_A, &info);
	else if (b < b->link_next && b > b->link_prev)
		move_swap(L_B, &info);
	check_reverse(info);
}

void	insertion_sort(t_all *info)
{
	int	count;

	count = 0;
	while (count < (info->count - 3))
	{
		put_at_head(find_smallest(info->l_a), L_A, info);
		count++;
		if (sorted(info->l_a))
			break ;
		move_push(L_A, info);
		conditional_move(info);
	}
	in_place_three(L_A, info);
	while (count-- > 0)
	{
		move_push(L_B, info);
	}
}
