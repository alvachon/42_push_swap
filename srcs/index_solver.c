/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:25:53 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 12:46:19 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_solved_index(int *index, t_all *info)
{
	t_node	*node;
	int		i;

	node = info->l_a;
	while (node->link_next != info->l_a)
	{
		i = 0;
		while (i < info->count)
			i = loop_index(index, i, &node, info);
		node = node->link_next;
	}
	while (i < info->count)
		i = loop_index(index, i, &node, info);
}

void	sort_list(int *solver, int len)
{
	int	max_i;
	int	median_i;
	int	min_i;
	int	pos;

	max_i = 0;
	while (max_i < len)
	{
		min_i = max_i;
		median_i = max_i + 1;
		pos = solver[max_i];
		while (median_i < len)
		{
			if (solver[median_i] < pos)
			{
				pos = solver[median_i];
				min_i = median_i;
			}
			median_i++;
		}
		pos = solver[max_i];
		solver[max_i] = solver[min_i];
		solver[min_i] = pos;
		max_i++;
	}
}

void	put_data(int *solver, t_node *l_a)
{
	t_node	*node;
	t_node	*head;
	int		i;

	node = l_a;
	head = node;
	i = 0;
	while (node->link_next != head)
	{
		solver[i] = node->data;
		i++;
		node = node->link_next;
	}
	solver[i] = node->data;
}

int	total_items(t_node *node)
{
	int		count;
	t_node	*head;

	if (!node)
		return (0);
	count = 0;
	head = node;
	while (node->link_next != head)
	{
		count++;
		node = node->link_next;
	}
	count++;
	return (count);
}

t_bool	solved_by_index(t_all *info)
{
	int	*solver;

	info->count = total_items(info->l_a);
	solver = malloc(info->count * sizeof(int));
	if (!solver)
		return (FALSE);
	put_data(solver, info->l_a);
	sort_list(solver, info->count);
	set_solved_index(solver, info);
	free(solver);
	return (TRUE);
}
