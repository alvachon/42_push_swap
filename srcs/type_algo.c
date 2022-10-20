/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:36:49 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 13:51:01 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	in_place_two(t_get stack, t_all *info)
{
	t_node	*node;

	node = ft_select(stack, info);
	if (node->index > node->link_next->index)
		move_swap(stack, info);
}

void	in_place_three(t_get stack, t_all *info)
{
	t_node	*list;

	list = ft_select(stack, info);
	put_at_tail(find_biggest(list), stack, info);
	in_place_two(stack, info);
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
	}
	in_place_three(L_A, info);
	while (count-- > 0)
	{
		move_push(L_B, info);
	}
}
