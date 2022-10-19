/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sandwich.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:22:40 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 18:55:19 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_index_smaller_than(int chunk, t_node *head)
{
	int	steps;

	steps = 0;
	while (head)
	{
		if (head->index <= chunk)
			return (steps);
		steps += 1;
		head = head->link_next;
	}
	return (0);
}

int		find_index_bigger_than(int chunk, t_node *head)
{
	int		steps;

	steps = 1;
	head = head->link_prev;
	while (head)
	{
		if (head->index <= chunk)
			return (steps);
		steps += 1;
		head = head->link_prev;
	}
	return (0);
}

void	do_less_steps(int option_1, int option_2, t_all *info)
{	
	if (option_1 <= option_2)
		repeat_op(move_rotate, option_1, L_A, info);
	else
		repeat_op(move_reverse_rotate, option_2, L_A, info);
	move_push(L_A, info);
}

void	return_to_la(t_all *info)
{
	while (info->l_b)
	{
		put_at_head(find_biggest(info->l_b), L_B, info);
		move_push(L_B, info);
	}
}

void	sandwich_sort(t_all *info, int chunk_size)
{
	int		steps[2];
	int 	chunk;
	int 	count;

	chunk = chunk_size;
	count = 0;
	while (info->l_a)
	{
		steps[0] = find_index_smaller_than(chunk, info->l_a);
		steps[1] = find_index_bigger_than(chunk, info->l_a);
		do_less_steps(steps[0], steps[1], info);
		if (info->l_b->index > chunk - chunk_size / 2)
			move_rotate(L_B, info);
		count++;
		if (count > chunk)
			chunk += chunk_size;
	}
	return_to_la(info);
}