/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:51:15 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 13:49:10 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	write_op(char *message)
{
	write(1, message, ft_strlen(message));
}

void	ft_display(t_node *head)
{
	t_node	*top;

	top = head;
	if (top == NULL)
	{
		printf(" null\n");
		return ;
	}
	while (top->link_next != head)
	{
		printf("%d ", top->data);
		top = top->link_next;
	}
	printf("%d ", top->data);
	printf("\n");
}

int	loop_index(int *index, int i, t_node **node, t_all *info)
{
	while (i < info->count)
	{
		if (index[i] == (*node)->data)
		{
			(*node)->index = i;
			return (i);
		}
		i++;
	}
	return (i);
}

t_node	*loop_add(t_node *head, int integer)
{
	t_node	*node;

	node = head;
	while (node->link_next != head)
	{
		if (!unique(integer, &node))
		{
			ft_list_destroyer(&node);
			return (av_error(&head, "Error\n"));
		}
	node = node->link_next;
	}
	head = ft_add_at_end(node->link_next, node, integer);
}
